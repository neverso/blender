/**
 * $Id:
 *
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
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
 * Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * The Original Code is Copyright (C) 2008 Blender Foundation.
 * All rights reserved.
 *
 * 
 * Contributor(s): Campbell Barton
 *
 * ***** END GPL LICENSE BLOCK *****
 */
#ifndef ED_CONSOLE_INTERN_H
#define ED_CONSOLE_INTERN_H

/* internal exports only */

struct ConsoleLine;
struct wmOperatorType;
struct ReportList;

/* TODO, make into a pref */
#define CONSOLE_SCROLLBACK_LIMIT 128 

/* console_draw.c */
void console_text_main(struct SpaceConsole *sc, struct ARegion *ar, struct ReportList *reports);
int console_text_height(struct SpaceConsole *sc, struct ARegion *ar, struct ReportList *reports); /* needed to calculate the scrollbar */

/* console_ops.c */
void console_history_free(SpaceConsole *sc, ConsoleLine *cl);
void console_scrollback_free(SpaceConsole *sc, ConsoleLine *cl);
ConsoleLine *console_history_add_str(const bContext *C, char *str, int own);
ConsoleLine *console_scrollback_add_str(const bContext *C, char *str, int own);

ConsoleLine *console_history_verify(const bContext *C);


void CONSOLE_OT_move(wmOperatorType *ot);
void CONSOLE_OT_delete(wmOperatorType *ot);
void CONSOLE_OT_insert(wmOperatorType *ot);

void CONSOLE_OT_history_append(wmOperatorType *ot);
void CONSOLE_OT_scrollback_append(wmOperatorType *ot);

void CONSOLE_OT_clear(wmOperatorType *ot);
void CONSOLE_OT_history_cycle(wmOperatorType *ot);
void CONSOLE_OT_zoom(wmOperatorType *ot);

enum { LINE_BEGIN, LINE_END, PREV_CHAR, NEXT_CHAR, PREV_WORD, NEXT_WORD };
enum { DEL_ALL, DEL_NEXT_CHAR, DEL_PREV_CHAR, DEL_SELECTION, DEL_NEXT_SEL, DEL_PREV_SEL };

/* defined in DNA_space_types.h */
static EnumPropertyItem console_line_type_items[] = {
	{CONSOLE_LINE_OUTPUT,	"OUTPUT", 0, "Output", ""},
	{CONSOLE_LINE_INPUT,	"INPUT", 0, "Input", ""},
	{CONSOLE_LINE_INFO,		"INFO", 0, "Information", ""},
	{CONSOLE_LINE_ERROR,	"ERROR", 0, "Error", ""},
	{0, NULL, 0, NULL, NULL}};

#endif /* ED_CONSOLE_INTERN_H */

