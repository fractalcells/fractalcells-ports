# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	slade
PORTVERSION=	3.1.4
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Modern editor for Doom-engine based games and source ports

LICENSE=	GPLv2

BROKEN=		fails to build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2019-09-04

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libsfml-system.so:devel/sfml \
		libftgl.so:graphics/ftgl \
		libfreeimage.so:graphics/freeimage

USE_GITHUB=	yes
GH_ACCOUNT=	sirjuddington
GH_PROJECT=	${PORTNAME:tu}

USES=		cmake compiler:c++11-lib gl pkgconfig
USE_WX=		3.0+
USE_GL=		glew
USE_CXXSTD=	c++11

CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE:FILEPATH="${WX_CONFIG}" \
		-DWX_GTK3:BOOL=OFF -DNO_WEBVIEW:BOOL=ON

PLIST_FILES=	bin/slade share/slade3/slade.pk3 \
		share/appdata/net.mancubus.SLADE.appdata.xml \
		share/applications/net.mancubus.SLADE.desktop \
		share/icons/net.mancubus.SLADE.png

OPTIONS_DEFINE=	FLUIDSYNTH
OPTIONS_DEFAULT=	FLUIDSYNTH

FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_RUN_DEPENDS=	${LOCALBASE}/share/sounds/sf2/FluidR3_GM.sf2:audio/fluid-soundfont
FLUIDSYNTH_CMAKE_OFF=	-DNO_FLUIDSYNTH:BOOL=ON

post-patch:
	@${REINPLACE_CMD} -e 's,"alsa","oss", ; \
		/share\/sounds\/sf2/s,/usr,${LOCALBASE},g' \
			${WRKSRC}/src/Audio/MIDIPlayer.cpp
	@${REINPLACE_CMD} -e 's,OpenBSD,${OPSYS},' \
		${WRKSRC}/src/External/zreaders/portable_endian.h
	@${REINPLACE_CMD} -e 's,wxVSCROLL,static_cast<long>(&),' \
		${WRKSRC}/src/MapEditor/UI/Dialogs/ActionSpecialDialog.cpp

.include <bsd.port.mk>
