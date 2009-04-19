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

#include "godc-proposal-open.h"

struct _GodcProposalOpenPrivate
{
	GeditDocument *doc;
	GeditWindow *window;
};

G_DEFINE_TYPE(GodcProposalOpen, godc_proposal_open, GSC_TYPE_PROPOSAL);

#define GODC_PROPOSAL_OPEN_GET_PRIVATE(object)(G_TYPE_INSTANCE_GET_PRIVATE ((object), GODC_TYPE_PROPOSAL_OPEN, GodcProposalOpenPrivate))
 
static gboolean
godc_proposal_open_apply(GscProposal* proposal, GtkTextView *view)
{
	GodcProposalOpen *self = GODC_PROPOSAL_OPEN (proposal);
	GeditTab *tab = gedit_tab_get_from_document(self->priv->doc);
	gedit_window_set_active_tab(self->priv->window,tab);
	return TRUE;
}

static void
godc_proposal_open_class_init (GodcProposalOpenClass *klass)
{
	GObjectClass* object_class = G_OBJECT_CLASS (klass);
	g_type_class_add_private (object_class, sizeof(GodcProposalOpenPrivate));
	
	GscProposalClass *proposal_class = GSC_PROPOSAL_CLASS (klass);
	proposal_class->apply = godc_proposal_open_apply;
}

static void
godc_proposal_open_init (GodcProposalOpen *self)
{
	self->priv = GODC_PROPOSAL_OPEN_GET_PRIVATE (self);
}

GscProposal*
godc_proposal_open_new (GeditWindow *window,
		       GeditDocument *doc,
		       GdkPixbuf *icon)
{
	/* FIXME Check objects */
	gchar *name = gedit_document_get_short_name_for_display (doc);
	gchar *info = gedit_document_get_uri_for_display (doc);
	GodcProposalOpen *self = GODC_PROPOSAL_OPEN (g_object_new (GODC_TYPE_PROPOSAL_OPEN, 
								 "label", name,
								 "info", info,
								 "icon", icon,
								 NULL));
	self->priv->doc = doc;
	self->priv->window = window;
	g_free (name);
	g_free (info);
	return GSC_PROPOSAL (self);
}



