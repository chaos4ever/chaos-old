/* $Id$ */
/* Abstract: ELF execution library return values. */
/* Authors: Henrik Hallin <hal@chaosdev.org>
            Per Lundberg <plundis@chaosdev.org> */

/* Copyright 2000 chaos development. */

/* This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation; either version 2 of
   the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
   USA. */

#ifndef __LIBRARY_EXECUTE_ELF_RETURN_VALUES_H__
#define __LIBRARY_EXECUTE_ELF_RETURN_VALUES_H__

/* Return values. */

enum
{
  /* The function completed successfully. */

  EXECUTE_ELF_RETURN_SUCCESS,
  EXECUTE_ELF_RETURN_ELF_UNSUPPORTED,
  EXECUTE_ELF_RETURN_IMAGE_INVALID,

  /* FIXME */

  EXECUTE_ELF_RETURN_FAILED
};

#endif /* !__LIBRARY_EXECUTE_ELF_RETURN_VALUES_H__ */
