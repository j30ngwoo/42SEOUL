/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:48:30 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/08/03 17:11:41 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# define MANDATORY 0
# define BONUS 1
# define TEMPFILE_PATH "./pipex_tempfile"

typedef struct s_pipex_info
{
	int		pipe1[2];
	int		pipe2[2];
	int		infile_fd;
	int		outfile_fd;
	char	*infile_name;
	char	*outfile_name;
	char	**cmd_strs;
	char	**env;
	int		process_num;
	char	**split_paths;
	int		bonus_flag;
	int		heredoc_flag;
	char	*limiter;
}	t_pipex_info;

// init
void	init_info(int ac, char **av, char **env, t_pipex_info *info);
void	parse_env_path(char **env, t_pipex_info *info);

// fork
void	fork_process(int process_index, t_pipex_info *info);
pid_t	protected_fork(int process_index);
void	wait_children(int child_num);
void	parent_process_after_fork(int process_index, t_pipex_info *info);
void	transfer_pipe2_to_pipe1(int pipe1[2], int pipe2[2]);

// child
void	child_process(int process_index, t_pipex_info *info);
void	set_io_pipe(int process_index, t_pipex_info *info);
void	exec_cmd(int process_index, t_pipex_info *info);
void	find_cmd_path(char **cmd_path, char *cmd_name, t_pipex_info *info);

// open in / out file
void	open_infile(t_pipex_info *info);
void	open_outfile(t_pipex_info *info);
void	open_outfile_to_append_mode(t_pipex_info *info);

// open heredoc
void	select_new_tempfile(t_pipex_info *info);
void	read_from_stdin_save_to_tempfile(t_pipex_info *info);
int		check_if_line_is_limiter(char *line, t_pipex_info *info);
void	remove_tempfile(t_pipex_info *info);

// protected funcs
char	**protected_split(char const *s, char c);
void	*protected_calloc(size_t count, size_t size);
void	protected_pipe(int fd[2]);
int		protected_close(int fd);
char	*protected_strndup(const char *s1, size_t n);

char	*protected_strjoin(char const *s1, char const *s2);
void	*protected_realloc(void *ptr, size_t size);
char	*protected_strdup(const char *s1);
char	*protected_itoa(int n);
int		protected_unlink(const char *pathname);

char	*protected_get_next_line(int fd);
ssize_t	protected_read(int fildes, void *buf, size_t nbyte);
int		protected_open(const char *path, int oflag, mode_t mode);

// termi
void	pipex_perror(char *message);
void	exit_with_pipex_perror(char *message);
void	cmd_not_found(char *cmd_name);
void	free_strs(char **strs);

#endif