/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:46:27 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/27 18:15:31 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFF_SIZE 3
# define ALL_B_M ft_modul_int((*b)->all)
# define RES_B_M ft_modul_int((*b)->result)
# define ALL_B (*b)->all
# define RES_B (*b)->result
# define OP_B (*b)->operations
# define OP_B_M ft_modul_int((*b)->operations)
# define OP_M ft_modul_int(min->operations)
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct		s_swap
{
	int				number;
	int				i_por;
	int				c_por;
	int				operations;
	int				all;
	int				turn;
	int				result;
	struct s_swap	*next;
	struct s_swap	*prev;
}					t_swap;

typedef struct		s_min
{
	int				max;
	int				all;
	int				iter;
	int				min_res;
	int				operations;
}					t_min;

void				ft_sa_sb(t_swap *list, int i);
void				ft_pa_pb(t_swap **one, t_swap **two, int i);
void				ft_ra_rb(t_swap **list, int i);
void				ft_rra_rrb(t_swap **list, int i);
int					get_next_line(const int fd, char **line);
int					ft_reading(int ac, char *av[], t_swap **list);
void				ft_filling(char *av, t_swap **list, t_swap **d, \
					t_swap *tmp);
void				ft_repeat(t_swap **list, t_swap *tmp);
void				cycle(t_swap *list, int i);
void				ft_order(int *s, t_swap *list, int r);
void				ft_add_number(int *s, t_swap *list);
void				ft_compare(t_swap *list, t_swap *b);
void				error();
void				ft_colvo_operations(t_swap **a, t_swap **ochek, int i, \
					int turn);
void				ft_choice(t_swap *list, int max);
void				ft_minimum(t_swap **list, int i);
void				ft_operations(t_swap **list, int result);
void				ft_null_list (t_swap *list);
int					ft_average(t_swap *a);
void				ft_push_in_a(t_swap **a, t_swap **b, int turn);
void				ft_push_in_a1(t_swap **a, t_swap **b, t_min *min,
					int turn);
int					ft_chosen_a(t_swap *a, int i_por);
void				ft_operations_b(t_swap **b, t_min *min, t_swap **a);
void				ft_sort_a_3(t_swap **a);
void				ft_free_list(t_swap *list);
void				ft_chose_b(t_swap *list, int max);
void				execution_end(t_swap **a, t_swap **b, char *line);
void				ft_pa_pb_end(t_swap **one, t_swap **two);
void				ft_sort_or_not_sort(t_swap *a);
void				ft_push(t_swap *a, t_swap *b, int turn);
void				ft_sort_a_min(t_swap **a);
void				ft_push_min(t_swap *a, t_swap *b);
void				ft_look_up_x(t_swap **a, t_swap **b, int i);
void				ft_what_operations(t_swap **a, t_swap **b);
void				ft_list_parametrs(t_min *min, t_swap **b);
void				ft_operations_1(t_swap **b, int all, int result, \
					t_swap **a);
void				ft_operations_2(t_swap **b, int all, int result, \
					t_swap **a);
void				ft_operations_3(t_swap **b, int all, int result, \
					t_swap **a);
void				red(void);
void				green(void);
void				reset(void);
void				cyan(void);
void				vizualization(t_swap *psa, t_swap **psb);
void				only_a(t_swap **a);
void				only_b(t_swap **b);
void				end_of_vizualization(int c_por);
void				ft_variables(t_min *min, t_swap *b);
void				ft_big_b(t_swap **a, t_swap **b, t_min *min);
void				ft_av(int j, char *av);
#endif
