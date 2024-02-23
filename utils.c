#include "printftest.h"

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*substr(char const *s, unsigned int start, size_t len)
{
	char	*c;

	if (s == NULL)
		return (NULL);
	if (start >= strlen(s))
		len = 0;
	len = min(len, (strlen(s) - start));
	c = malloc(len + 1);
	if (c != NULL)
	{
		if (len > 0)
			memcpy(c, (s + start), len);
		c[len] = 0;
	}
	return (c);
}

static int	count_words(const char *s, char sep)
{
	int	i;

	i = 0;
	if (sep == 0)
		return (1);
	while (*s == sep)
		s++;
	while (*s)
	{
		i++;
		while (*s != sep && *s)
			s++;
		while (*s == sep && *s)
			s++;
	}
	return (i);
}

static int	next_sep(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**split(char const *s, char c)
{
	char	**tab;
	int		len;
	int		i;

	if (s == NULL)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == 0)
			break ;
		len = next_sep(s, c);
		tab[i] = substr(s, 0, len);
		s += len;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int getTerminalWidth()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}


