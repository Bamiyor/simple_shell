#include "shell.h"

/**
 * input_buffer - buffers chained commands
 * @info: Parameter struct
 * @buf: The address of buffer
 * @len: Address of len variable
 *
 * Return: Number of bytes read
 */

ssize_t input_buffer(info_t info, char *buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!len) {/if nothing left in the buffer, fill it */
	free(*buf);
	*buf = NULL;
	signal(SIGINT, sigintHandler);

#if USE_GETLINE
	r = getline(buf, &len_p, stdin);
#else
	r = custom_getline(info, buf, &len_p);
#endif

			if (r > 0)
			{
				if ((*buf)[r - 1] == '\n')
				{
					(buf)[r - 1] = '\0'; / Remove trailing newline */
						r--;
				}

				info->linecount_flag = 1;
				remove_comments(*buf);
				build_history_list(info, *buf, info->histcount++);

				*len = r;
				info->cmd_buf = buf;
			}
	}

	return (bytes_read);
}

/**
 * get_input - gets a line minus the newline
 * @info: Parameter struct
 *
 * Return: Bytes read
 */

ssize_t get_input(info_t *info)
{
	static char buf; / The ';' command chain buffer */
		static size_t i, j, len;
	ssize_t bytes_read = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	bytes_read = input_buffer(info, &buf, &len);

	if (bytes_read == -1)
		return (-1);

	/*
	 * We have commands left in the chain buffer
	 */

	if (len){

		/*
		 * Initialize a new iterator to the current buf position
		 */

		j = i;

		/*
		 * Get a pointer for return
		 */

		p = buf + i;

		check_chain(info, buf, &j, i, len);

		/*
		 * Iterate to semicolon or end
		 */

		while (j < len) {
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		/*
		 * Increment past nulled ';'
		 */

		i = j + 1;

		/*
		 * Reached the end of the buffer?
		 */

		if (i >= len)
		{

			/*
			 * Reset position and length
			 */

			i = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return _strlen(p);
	}

	/*
	 * Not a chain; pass back buffer from custom_getline()
	 */

	*buf_p = buf;

	/*
	 * Return length of buffer from custom_getline() */

	return (bytes_read);
}

/**
 * read_buffer - reads a buffer
 * @info: Paramter struct
 * @buf: Buffer
 * @i: Size
 *
 * Return: number of bytes read
 */

ssize_t read_buffer(info_t *info, char *buf, size_t *i) {
	ssize_t bytes_read = 0;

	if (*i)
		return (0);

	bytes_read = read(info->readfd, buf, READ_BUF_SIZE);

	if (bytes_read >= 0)
		*i = bytes_read;

	return (bytes_read);
}

/**
 * custom_getline - gets the next line of input from STDIN
 * @info: Parameter struct
 * @ptr: Address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 * 
 * Return: s
 */

int custom_getline(info_t info, char *ptr, size_t *length) {
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t bytes_read = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;

	if (p && length)
		s = *length;

	if (i == len)
		i = len = 0;

	bytes_read = read_buffer(info, buf, &len);

	if (bytes_read == -1 || (bytes_read == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);

	if (!new_p){/MALLOC FAILURE! /
		return p ? (free(p), -1) : -1;
	}

	if (s) {
		_strncat(new_p, buf + i, k - i);
	} else {
		_strncpy(new_p, buf + i, k - i + 1);
	}

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;

	*ptr = p;
	return (s);
	}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: The signal number
 */

void sigintHandler(_attribute_((unused))int sig_num)
{
	_puts("\n$");
	_putchar(BUF_FLUSH);
}
