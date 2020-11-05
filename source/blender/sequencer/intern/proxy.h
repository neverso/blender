/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2004 Blender Foundation.
 * All rights reserved.
 */

#pragma once

/** \file
 * \ingroup sequencer
 */

#ifdef __cplusplus
extern "C" {
#endif

struct SeqRenderData;
struct ImBuf;
struct Sequence;

#define PROXY_MAXFILE (2 * FILE_MAXDIR + FILE_MAXFILE)
struct ImBuf *seq_proxy_fetch(const struct SeqRenderData *context, struct Sequence *seq, int cfra);
bool seq_proxy_get_custom_file_fname(struct Sequence *seq, char *name, const int view_id);

#ifdef __cplusplus
}
#endif
