/*
 * gsc-geditopendoc-provider.h
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

#ifndef __GEDITOPENDOC_PROVIDER_H__
#define __GEDITOPENDOC_PROVIDER_H__

#include <glib.h>
#include <glib-object.h>
#include <gedit/gedit-plugin.h>
#include <gtksourcecompletion/gsc-provider.h>
#include <gtksourcecompletion/gsc-completion.h>

G_BEGIN_DECLS


#define TYPE_GSC_GEDITOPENDOC_PROVIDER (gsc_geditopendoc_provider_get_type ())
#define GSC_GEDITOPENDOC_PROVIDER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_GSC_GEDITOPENDOC_PROVIDER, GscGeditopendocProvider))
#define GSC_GEDITOPENDOC_PROVIDER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_GSC_GEDITOPENDOC_PROVIDER, GscGeditopendocProviderClass))
#define IS_GSC_GEDITOPENDOC_PROVIDER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_GSC_GEDITOPENDOC_PROVIDER))
#define IS_GSC_GEDITOPENDOC_PROVIDER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_GSC_GEDITOPENDOC_PROVIDER))
#define GSC_GEDITOPENDOC_PROVIDER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_GSC_GEDITOPENDOC_PROVIDER, GscGeditopendocProviderClass))

#define GSC_GEDITOPENDOC_PROVIDER_NAME "GscGeditopendoc"

typedef struct _GscGeditopendocProvider GscGeditopendocProvider;
typedef struct _GscGeditopendocProviderClass GscGeditopendocProviderClass;
typedef struct _GscGeditopendocProviderPrivate GscGeditopendocProviderPrivate;

struct _GscGeditopendocProvider {
	GObject parent;
	GscGeditopendocProviderPrivate *priv;	
};

struct _GscGeditopendocProviderClass {
	GObjectClass parent;
};

GType gsc_geditopendoc_provider_get_type ();

GscGeditopendocProvider*
gsc_geditopendoc_provider_new(GeditWindow *window);

G_END_DECLS

#endif
