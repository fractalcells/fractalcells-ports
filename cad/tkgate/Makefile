# $FreeBSD$

PORTNAME=	tkgate
PORTVERSION=	2.1
CATEGORIES=	cad
MASTER_SITES=	http://cdn.bitbucket.org/starling13/tkgate/downloads/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Event driven digital circuit simulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES+=		iconv:translit tk:build,run autoreconf
USE_GNOME=	pango
OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/wish|${WISH}|g' ${WRKSRC}/scripts/tree.tcl
	@${REINPLACE_CMD} -e \
		's|%%TCL_VER%%|${TCL_VER}|g; \
		s|%%TCL_INCLUDEDIR%%|${TCL_INCLUDEDIR}|g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/configure.ac

# Remove backup files somehow installed to the stagedir
post-install:
	${FIND} ${STAGEDIR}/${DATADIR} -name '*~' -delete -or -name '*~?' -delete

.include <bsd.port.mk>
