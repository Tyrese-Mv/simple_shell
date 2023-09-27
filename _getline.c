#include "shell.h"

/**
* read_buff - reads the line from the stream
* @buff: buffer to store the line read
* @buf_indx: current index of buffer
* @buf_size: size of buffer
* @stream: input strean to read from
*
* Return: no of read chars on success, -1 on failure
*/

ssize_t read_buff(char *buff, size_t *buf_indx, size_t *buf_size, FILE *stream)
{
	if (*buf_indx >= *buf_size)
	{
		*buf_size = read(fileno(stream), buff, sizeof(buff));
		*buf_indx = 0;

		if (*buf_size <= 0)
		{
			return ((*buf_size == 0) ?  (ssize_t)-1 : (ssize_t)*buf_size);
		}
	}
	return (0);
}

/**
* my_getline - reads a full line from a stream
* @lineptr: pointer to a buffer where the line will be stored
* @n: pointer to the size of the buffer(lineptr)
* @stream: the input stream to read from
*
* Return: Success - no of chars read,
* Failure returns -1.
*/
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[1024];
	static size_t buff_index, buff_size;
	char *line, *new_line;
	size_t line_index;
	ssize_t read_result = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	line = *lineptr;
	line_index = 0;
	while (1)
	{
		read_result = read_buff(buffer, &buff_index, &buff_size, stream);
		if (read_result < 0)
			return (-1);
		if (line_index >= *n - 1)
		{
			*n *= 2;
			new_line = realloc(*lineptr, *n);
			if (new_line == NULL)
			{
				return (-1);
			}
			*lineptr = new_line;
			line = new_line;
		}
		line[line_index] = buffer[buff_index];
		if (buffer[buff_index] == '\n')
		{
			line[line_index] = '\0';
			buff_index++;
			return (line_index);
		}
		buff_index++;
		line_index++;
	}
}
