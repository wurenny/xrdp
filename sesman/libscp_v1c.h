/*
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   xrdp: A Remote Desktop Protocol server.
   Copyright (C) Jay Sorg 2005-2006
*/

/**
 * 
 * @file libscp_v1c.h
 * @brief libscp version 1 client api declarations
 * @author Simone Fedele
 * 
 */

#ifndef LIBSCP_V1C_H
#define LIBSCP_V1C_H

#include "libscp_types.h"

enum SCP_CLIENt_STATES_E
{
  SCP_CLIENT_STATE_NO,
  SCP_CLIENT_STATE_WRONGPWD,
  SCP_CLIENT_STATE_PWDCHG_REQ,
  SCP_CLIENT_STATE_PWDCHG_CANCEL,
  SCP_CLIENT_STATE_
};

/* client API */
/* 001 */ SCP_CLIENT_STATES_E scp_v1c_connect(struct SCP_CONNECTION* c, struct SCP_SESSION* s);
/* 004 */ SCP_CLIENT_STATES_E scp_v1c_resend_credentials(struct SCP_CONNECTION* c, struct SCP_SESSION* s);

/* 021 */ SCP_CLIENT_STATES_E scp_v1c_pwd_change(struct SCP_CONNECTION* c, char* newpass);
/* 022 */ SCP_CLIENT_STATES_E scp_v1c_pwd_change_cancel(struct SCP_CONNECTION* c);

/* ... */ SCP_CLIENT_STATES_E scp_v1c_get_session_list(struct SCP_CONNECTION* c, int* scount, struct SCP_DISCONNECTED_SESSION** s);
/* 041 */ SCP_CLIENT_STATES_E scp_v1c_select_session(struct SCP_CONNECTION* c, SCP_SID sid);
/* 042 */ SCP_CLIENT_STATES_E scp_v1c_select_session_cancel(struct SCP_CONNECTION* c);

#endif
