# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flrig
PORTVERSION=	1.3.47
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/fldigi/${PORTNAME}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Ham Radio rig control program, cooperates with fldigi

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig \
		libfltk.so:x11-toolkits/fltk

USES=		gmake jpeg
USE_XORG=	x11 xrender xcursor xfixes xext xft xinerama

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	FLTK_CONFIG="${LOCALBASE}/bin/fltk-config"
PLIST_FILES=	bin/flrig share/applications/flrig.desktop \
		 share/pixmaps/flrig.xpm
OPTIONS_DEFINE=	NATIVE_OPT

NATIVE_OPT_DESC=	Enable Native Optimizations

NATIVE_OPT_CONFIGURE_ON+=	--enable-optimizations=native
NATIVE_OPT_CONFIGURE_OFF+=	--enable-optimizations=none

CFLAGS_powerpc64=	-mminimal-toc

.include <bsd.port.mk>
