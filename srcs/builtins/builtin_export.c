/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:27:50 by sehhong           #+#    #+#             */
/*   Updated: 2021/12/16 16:18:27 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

//
void    builtin_export(void)
{
    
}

//water=haha로 쉘변수 업로드 가능 ->근데 이것도 구현하라는 말은 없지 않나?
//export water -> 등록되어 있던 쉘변수가 환경변수에 들어감.
//export -> declare -x 환경변수list 보여줌
//export water=haha -> 바로 환경변수로 저장.
//export water asdf fdsa qwer