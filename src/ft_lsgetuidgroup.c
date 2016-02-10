/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsgetuidgroup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 17:16:29 by msoudan           #+#    #+#             */
/*   Updated: 2015/06/08 17:42:32 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*userNameFromId(uid_t uid)
{
	struct passwd	*pwd;

	pwd = getpwuid(uid);
	return (pwd == NULL) ? NULL : (char *)pwd->pw_name;
}

char				*groupNameFromId(gid_t gid)
{
	struct group	*grp;

	grp = getgrgid(gid);
	return (grp == NULL) ? NULL : (char *)grp->gr_name;
}
