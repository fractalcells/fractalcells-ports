# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	dataplot
DISTVERSION=	20190426
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free software system for statistical visualization

LICENSE=	PD

LIB_DEPENDS=	libgd.so:graphics/gd \
		libpng.so:graphics/png

USES=		gmake fortran jpeg readline

USE_GITHUB=	yes
GH_ACCOUNT=	usnistgov
GH_PROJECT=	dataplot
GH_TAGNAME=	7236db0

USE_XORG=	x11 xi
USE_GNOME+=	cairo
WRKSRC_SUBDIR=	src
MAXOBV?=	450000	# Change if you need more observations/variable

OPTIONS_DEFINE=	DOCS

FFLAGS+=	-DLINUX -fdefault-real-8 -fdefault-double-8 -std=legacy

post-patch:
	@${REINPLACE_CMD} -e 's/MAXOBV=1500000/MAXOBV=${MAXOBV}/' \
		${WRKSRC}/DPCOPA.INC
	@${REINPLACE_CMD} \
		-e 's;%%FC%%;${FC};' \
		-e 's;%%CC%%;${CC};' \
		-e 's;%%FFLAGS%%;${FFLAGS};' \
		-e 's;%%CFLAGS%%;${CFLAGS};' \
		-e 's;%%DATADIR%%;${DATADIR};' \
		-e 's;%%LOCALBASE%%;${LOCALBASE};g' ${WRKSRC}/Makefile

post-build:
	${STRIP_CMD} ${WRKSRC}/dataplot

.include <bsd.port.mk>
