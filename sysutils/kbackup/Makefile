# $FreeBSD$

PORTNAME=	kbackup
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	2
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Backup program with an easy to use user interface

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:5 \
		qt:5 shared-mime-info tar:xz
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons ecm i18n iconthemes itemviews jobwidgets kio \
		notifications service solid widgetsaddons xmlgui
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
