/*
 *
 * Copyright (C) 2008 - perriman
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __GODC_PROPOSAL_OPEN_H__
#define __GODC_PROPOSAL_OPEN_H__

#include <glib.h>
#include <glib-object.h>
#include <gedit/gedit-plugin.h>
#include <gtksourceview/gtksourcecompletionproposal.h>

G_BEGIN_DECLS

typedef struct _GodcProposalOpenPrivate GodcProposalOpenPrivate;
typedef struct _GodcProposalOpen GodcProposalOpen;
typedef struct _GodcProposalOpenClass GodcProposalOpenClass;

struct _GodcProposalOpen
{
	GObject parent;
	GodcProposalOpenPrivate *priv;
};

struct _GodcProposalOpenClass
{
	GObjectClass parent_class;
};

#define GODC_TYPE_PROPOSAL_OPEN (godc_proposal_open_get_type ())
#define GODC_PROPOSAL_OPEN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GODC_TYPE_PROPOSAL_OPEN, GodcProposalOpen))
#define GODC_PROPOSAL_OPEN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GODC_TYPE_PROPOSAL_OPEN, GodcProposalOpenClass))
#define GODC_IS_PROPOSAL_OPEN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GODC_TYPE_PROPOSAL_OPEN))
#define GODC_IS_PROPOSAL_OPEN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GODC_TYPE_PROPOSAL_OPEN))
#define GODC_PROPOSAL_OPEN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GODC_TYPE_PROPOSAL_OPEN, GodcProposalOpenClass))

GType		 godc_proposal_open_get_type	(void) G_GNUC_CONST;

GtkSourceCompletionProposal	*godc_proposal_open_new(GeditWindow *window,
						 GeditDocument *doc,
						 GdkPixbuf *icon);



G_END_DECLS

#endif
