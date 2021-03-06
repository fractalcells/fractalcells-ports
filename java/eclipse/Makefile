# Created by: Jonathan Chen <jonc@chen.org.nz>
# $FreeBSD$

PORTNAME=	eclipse
PORTVERSION=	4.11
PORTREVISION=	1
CATEGORIES=	java devel

# Update to git-tag on git.eclipse.org
ECLIPSE_TAG=	R4_11
ECLIPSE_TSTAMP=	20190321-0023

ECLIPSE_SUFX=	${ECLIPSE_TAG}.tar.xz
ECLIPSE_MODULES=jdt/eclipse.jdt \
		jdt/eclipse.jdt.core \
		jdt/eclipse.jdt.core.binaries \
		jdt/eclipse.jdt.debug \
		jdt/eclipse.jdt.ui \
		pde/eclipse.pde.build \
		pde/eclipse.pde.ui \
		platform/eclipse.platform \
		platform/eclipse.platform.common \
		platform/eclipse.platform.debug \
		platform/eclipse.platform.releng \
		platform/eclipse.platform.releng.aggregator \
		platform/eclipse.platform.resources \
		platform/eclipse.platform.runtime \
		platform/eclipse.platform.swt \
		platform/eclipse.platform.swt.binaries \
		platform/eclipse.platform.team \
		platform/eclipse.platform.text \
		platform/eclipse.platform.ua \
		platform/eclipse.platform.ui \
		platform/eclipse.platform.ui.tools \
		equinox/rt.equinox.binaries \
		equinox/rt.equinox.bundles \
		equinox/rt.equinox.framework \
		equinox/rt.equinox.p2
# Each Eclipse module has its own MASTER_SITE
.for M in ${ECLIPSE_MODULES}
MASTER_SITES+=	https://git.eclipse.org/c/${M}.git/snapshot/:${M:C/[\.\/]//g}
DISTFILES+=	${M:C/.*\///}-${ECLIPSE_SUFX}:${M:C/[\.\/]//g}
.endfor

DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jonc@chen.org.nz
COMMENT=	Eclipse IDE 2019-03

LICENSE=	EPL

ONLY_FOR_ARCHS=	amd64 powerpc64

BUILD_DEPENDS=	git:devel/git-lite \
		${LOCALBASE}/share/java/maven/bin/mvn:devel/maven
LIB_DEPENDS=	libsecret-1.so:security/libsecret \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3
USES=		compiler:c++11-lang gmake pkgconfig gnome
USE_GNOME=	gtk30

USE_GITHUB=	yes
GH_ACCOUNT=	daemonblade
GH_PROJECT=	eclipse-maven-repo

USE_JAVA=	yes
JAVA_VERSION=	1.8

DESKTOP_ENTRIES="Eclipse" \
		"${COMMENT}" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Development;IDE;Java;" \
		"false"

SUB_FILES=	${PORTNAME}

MAVEN_ENV=	MAVEN_OPTS=-Xmx1024m CC=${CC}
MAVEN_REPO=	-Dmaven.repo.local=${WRKDIR}/${GH_PROJECT}-${PORTVERSION}
MAVEN_ECLIPSE=	-Dnative=gtk.freebsd.${ARCH} -Dcomparator.repo=file://${WRKDIR}/${GH_PROJECT}-${PORTVERSION}/p2-stub -DforceContextQualifier=v${ECLIPSE_TSTAMP}

ECLIPSE_RESULT=	eclipse.platform.releng.tychoeclipsebuilder/sdk/target/products/org.eclipse.sdk.ide-freebsd.gtk.${ARCH}.tar.gz

# Let's abuse this to get to the right place.
WRKSRC_SUBDIR=	../eclipse.platform.releng.aggregator-${ECLIPSE_TAG}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAVEN_ENV} mvn --offline ${MAVEN_REPO} ${MAVEN_ECLIPSE} -DskipTests clean verify

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${TAR} -x --directory ${STAGEDIR}${DATADIR}/.. --file ${WRKSRC}/${ECLIPSE_RESULT}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

# generate dynamic plist, to cater for different ARCHS
post-install:
	cd ${STAGEDIR}${PREFIX} && ${FIND} -s bin/${PORTNAME} share/${PORTNAME} -not -type d >> ${TMPPLIST}
	cd ${STAGEDIR}${PREFIX} && ${FIND} -ds share/${PORTNAME} -type d | ${SED} -e 's,^,@dir ,' >> ${TMPPLIST}

.include <bsd.port.mk>
