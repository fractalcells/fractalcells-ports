# $FreeBSD$

PORTNAME=	kompare
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	2
CATEGORIES=	textproc kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Diff/Patch Frontend

LIB_DEPENDS=	libkomparediff2.so:textproc/libkomparediff2

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		doctools ecm i18n iconthemes jobwidgets kio parts service \
		sonnet texteditor textwidgets widgetsaddons xmlgui
USE_QT=		concurrent core dbus gui network printsupport widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
