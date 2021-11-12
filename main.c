/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:34:20 by achopper          #+#    #+#             */
/*   Updated: 2021/05/04 19:54:27 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libasm.h"

int g_test_num;

void print_res(ssize_t ret_ft_w, ssize_t ret_w, int ft_w_er, int w_er, short
test_num, char *name)
{
	if (ret_ft_w == ret_w && ft_w_er == w_er)
	{
		printf("ft_%s err = %d\nret = %zd\n", name, ft_w_er, ret_ft_w );
		printf("%s err = %d\nret = %zd\nOK!\n", name, w_er, ret_ft_w);
		g_test_num++;
		if	(ft_w_er != 0 || w_er != 0)
		{
			perror("error");
			write(1, "\n", 1);
		}
		else
			write(1, "\n", 1);
	}
	else
		printf("%s %d test KO\n",name, test_num);
	errno = 0;
}

void print_strlen_res(size_t ft_ret, size_t str_ret, short test_num)
{
	if(ft_ret == str_ret)
	{
		printf("ft_strlen ret = %zd\nstrlen ret = %zd\nOK!\n\n", ft_ret,
			   str_ret);
		g_test_num++;
	}
	else
		printf("strlen test %d KO!\n",test_num);
}

void print_strcmp_res(char *s1, char *s2, int test_num)
{
	int ret1 = ft_strcmp(s1, s2);
	int ret2 = strcmp(s1, s2);
	if (ret1 == ret2)
	{
		printf("ft_ret = %d\nstrcmp ret = %d\nOK!\n",ret1, ret2);
		g_test_num++;
	}
	else
		printf("test no %d KO!",test_num);
}

void print_strcpy_res(char *dst, char *src, int test_num)
{
	ft_strcpy(dst, src);
	src[0] = 0;
	ft_strcpy(src, dst);
	if(ft_strcmp(dst,src) == 0)
	{
		printf("ft_res = %s\nstrcpy res = %s\ntest no %d OK!\n",dst,
		 src, test_num);
		g_test_num++;
	}
	else
		printf("test %d KO!", test_num);

}

int main()
{
	char *t1 = "Hihihi";
	g_test_num = 0;
	printf("___________ft_write test__________\n");
	char *buf = "Hello asm\n";
	ssize_t w1 = ft_write(1, buf, ft_strlen(buf));
	int w_er1 = errno;
	ssize_t w2 = write(1, buf, ft_strlen(buf));
	int w_er2 = errno;
	print_res(w1, w2, w_er1, w_er2, 1,"write");
	w1 = ft_write(-1, buf, ft_strlen(buf));
	w_er1 = errno;
	w2 = write(-1, buf, ft_strlen(buf));
	w_er2 = errno;
	print_res(w1, w2, w_er1, w_er2, 2, "write");
	w1 = ft_write(1, NULL, ft_strlen(buf));
	w_er1 = errno;
	w2 = write(1, NULL, ft_strlen(buf));
	w_er2 = errno;
	print_res(w1, w2, w_er1, w_er2, 3, "write");
	w1 = ft_write(0, buf, 0);
	w_er1 = errno;
	w2 = write(0, buf, 0);
	w_er2 = errno;
	print_res(w1, w2, w_er1, w_er2, 4, "write");
	w1 = ft_write(1, buf, -1);
	w_er1 = errno;
	w2 = write(1, buf, -1);
	w_er2 = errno;
	print_res(w1, w2, w_er1, w_er2, 5, "write");
	int fd = open("test.txt", O_RDWR | O_CREAT, 0777);
	char *test_fd_wr = "testing ft_write and read in file, if you see this "
					"test is succsessful";
	ft_write(fd, test_fd_wr, ft_strlen(test_fd_wr));
	ft_read(fd, &test_fd_wr, ft_strlen(test_fd_wr));
	close(fd);
	fd = open("test1.txt", O_RDWR | O_CREAT, 0777);
	w1 = ft_write(fd, test_fd_wr, ft_strlen(test_fd_wr));
	if	(w1 < 0)
	{
		printf("error in file test");
		g_test_num += 10;
	}
	close(fd);

	printf("___________ft_strlen test__________\n");
	w1 = ft_strlen("babushka");
	w2 = strlen("babushka");
	print_strlen_res(w1, w2, 1);
	w1 = ft_strlen("");
	w2 = strlen("");
	print_strlen_res(w1, w2, 2);
	w1 = ft_strlen("Cvetoch\0ek");
	w2 = strlen("Cvetoch\0ek");
	print_strlen_res(w1, w2, 3);
	w1 = ft_strlen("very "
				   "loooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"
				   "ooooooooooooooooooooooooooooooooooooooooooooong string");
	w2 = strlen("very "
				"loooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"
				"ooooooooooooooooooooooooooooooooooooooooooooong string");
	print_strlen_res(w1, w2, 4);
	w1 = ft_strlen(t1);
	w2 = strlen(t1);
	print_strlen_res(w1, w2, 5);


	printf("___________ft_read test__________\n");
	char a[6000];
	char b[6000];
	fd = open("./test.txt", O_RDONLY);
	w1 = ft_read(fd, a, 4000);
	w_er1 = errno;
	close(fd);
	fd = open("./test.txt", O_RDONLY);
	w2 = read(fd, b, 4000);
	w_er2 = errno;
	close(fd);
	print_res(w1, w2, w_er1, w_er2, 1, "read");
	w1 = ft_read(0, a, 100);
	w_er1 = errno;
	w2 = read(0, b, 100);
	w_er2 = errno;
	print_res(w1, w2, w_er1, w_er2, 2, "read");
	w1 = ft_read(1, a, 100);
	w_er1 = errno;
	w2 = read(1, b, 100);
	w_er2 = errno;
	print_res(w1, w2, w_er1, w_er2, 3, "read");
	w1 = ft_read(-1, a, 100);
	w_er1 = errno;
	w2 = read(-1, b, 100);
	w_er2 = errno;
	print_res(w1, w2, w_er1, w_er2, 4, "read");
	w1 = ft_read(1, a, 0);
	w_er1 = errno;
	w2 = read(1, b, 0);
	w_er2 = errno;
	print_res(w1, w2, w_er1, w_er2, 5, "read");
	w1 = ft_read(1, a, -1);
	w_er1 = errno;
	w2 = read(1, b, -1);
	w_er2 = errno;
	print_res(w1, w2, w_er1, w_er2, 6, "read");

	printf("______________ft_strcmp test________________\n");
	char *s1 = "babu";
	char *s2 = "bab";
	print_strcmp_res(s1, s2, 1);
	s1 = "Cvetok";
	s2 = "Cvetochek";
	print_strcmp_res(s1, s2, 2);
	s1 = "Pushka";
	s2 = "Pushka";
	print_strcmp_res(s1, s2, 3);
	s1 = " ";
	s2 = " ";
	print_strcmp_res(s1, s2, 4);
	s1 = " ";
	s2 = "";
	print_strcmp_res(s1, s2, 5);
	s1 = "";
	s2 = "";
	print_strcmp_res(s1, s2, 6);
	s1 = "";
	s2 = " ";
	print_strcmp_res(s1, s2, 7);


	printf("______________ft_strcpy test________________\n");
	char bb[500];
	char ba[500] = "pups";
	print_strcpy_res(bb, ba, 1);
	ft_strcpy(ba, "Pechenka");
	print_strcpy_res(bb, ba, 2);
	ft_strcpy(ba, "");
	print_strcpy_res(bb, ba, 3);
	ft_strcpy(ba, "very "
			   "loooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"
	  "ooooooooooooooooooooooooooooooooooooooooooooong string");
	print_strcpy_res(bb, ba, 4);
	ft_strcpy(bb, "hi");
	ft_strcpy(ba, "");
	print_strcpy_res(bb, ba, 5);
	ft_strcpy(ba, "Krutotenushka");
	print_strcpy_res(bb, ba, 6);

	printf("______________ft_strdub test________________\n");
	t1 = "Knopochka";
	char *t2 = ft_strdup(t1);
	print_strcmp_res(t1, t2, 1);
	t1 = "very "
	  "looooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"
   "oooooooooooooooooooooooooooooooooooooooong string";
	t2 = ft_strdup(t1);
	print_strcmp_res(t1, t2, 2);
	t1 = "";
	t2 = ft_strdup(t1);
	print_strcmp_res(t1, t2, 3);

	if(g_test_num == 32)
		printf("-----------TEST COMPLETE!!--------------\ndont forget to "
		 "check test1.txt\n");
	else
		printf("-----------TEST KO!!--------------\n");
	return 0;
}
