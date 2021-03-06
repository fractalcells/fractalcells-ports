# Created by: Oliver Eikemeier
# $FreeBSD$

PORTNAME=		bash
PATCHLEVEL=		7
PORTVERSION=		5.0.${PATCHLEVEL:S/^0//g}
PORTREVISION?=		0
CATEGORIES=		shells
MASTER_SITES=		GNU
DISTNAME=		${PORTNAME}-${PORTVERSION:R}
DIST_SUBDIR=		${PORTNAME}
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=		GNU/${PORTNAME}/${DISTNAME}-patches/
PATCHFILES!=		/usr/bin/jot -s " " -w \
			${PORTNAME}${PORTVERSION:R:S/.//g}-%03d \
			${PATCHLEVEL} 1 ${PATCHLEVEL}

MAINTAINER=		ehaupt@FreeBSD.org
COMMENT=		GNU Project's Bourne Again SHell

LICENSE=		GPLv3+
LICENSE_FILE=		${WRKSRC}/COPYING

# STATIC option requires special hardening treatment, see below.
USE_HARDENING=		safestack

OPTIONS_DEFINE=		FDESCFS HELP NLS STATIC SYSBASHRC SYSLOG DOCS
FDESCFS_DESC=		Enable use of /dev/fd
HELP_DESC=		Enable builtin help
SYSBASHRC_DESC=		Enable system-wide rc files

OPTIONS_DEFAULT=	HELP

USES=			bison cpe iconv makeinfo pathfix localbase
GNU_CONFIGURE=		yes
OPTIONS_SUB=		yes
CPE_VENDOR=		gnu

FDESCFS_CONFIGURE_ENV_OFF=	bash_cv_dev_fd=absent
FDESCFS_SUB_FILES=	pkg-message

HELP_CONFIGURE_ENABLE=	help-builtin
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

INFO=			bash

PORTDOCS=		FAQ INTRO CHANGES COMPAT NEWS POSIX RBASH README \
			bash.html bashref.html

CONFIGURE_ARGS+=	--without-bash-malloc \
			--disable-rpath \
			--enable-disabled-builtins \
			--with-libiconv-prefix=${ICONV_PREFIX}

.if empty(PKGNAMESUFFIX)
CONFLICTS+=		bash-static-[0-9]*
.else
CONFLICTS+=		bash-[0-9]*
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTATIC} || defined(NO_DYNAMICROOT) || (defined(NOSHARED) && ${NOSHARED:tl} != "no")
CONFIGURE_ARGS+=	--enable-static-link
LLD_UNSAFE=		yes
# For STATIC option undo all hardening.   This is a chicken vs. egg
# problem in the way the options and their actions are handled, but
# we end up with the correct port option state for hardening.
.for _HARDENING in ${USE_HARDENING}
PORT_OPTIONS:=		${PORT_OPTIONS:N${_HARDENING:tu}}
USES:=			${USES:N${_HARDENING}}
.endfor
.else
CONFIGURE_ARGS+=	--disable-static-link
# Bash symbols must be exported in order to link runtime plugins, i.e.,
# "enable -f". (Plugins are not supported for bash-static.)
LDFLAGS+=		-Wl,-export-dynamic
.endif
STANDARD_PATH=		/sbin:/bin:/usr/sbin:/usr/bin
CPPFLAGS+=		-DDEFAULT_PATH_VALUE='\"${STANDARD_PATH}:${LOCALBASE}/sbin:${LOCALBASE}/bin\"' \
			-DSTANDARD_UTILS_PATH='\"${STANDARD_PATH}\"'

post-patch:
# Ensure y.tab.c is regenerated
	${TOUCH} ${WRKSRC}/parse.y
	${RM} ${WRKSRC}/y.tab.c
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/doc/bash.1
.if ${PORT_OPTIONS:MSYSLOG}
	@${REINPLACE_CMD} \
	    -e "s|/\*.*#define SYSLOG_HISTORY .*\*/|#define SYSLOG_HISTORY|g" \
	    -e "s|/\*.*#define SYSLOG_SHOPT .*\*/|#define SYSLOG_SHOPT 1|g" \
	    ${WRKSRC}/config-top.h
.endif

post-patch-SYSBASHRC-on:
	@${REINPLACE_CMD} \
		-e "s|.*\(#define SYS_BASH.*\)\(/etc/.*\"\).*|\1${PREFIX}\2|" \
		${WRKSRC}/config-top.h

post-configure:
	@${FIND} ${WRKSRC} -name Makefile -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e "s|^DESTDIR *=|& ${DESTDIR}|"

pre-build:
	@${ECHO_CMD} $$((${PORTREVISION}-1)) > ${WRKSRC}/.build

post-install:
	${LN} -sf bash ${STAGEDIR}${PREFIX}/bin/rbash
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ \
		${WRKSRC}/doc/INTRO ${STAGEDIR}${DOCSDIR}
	for d in ${PORTDOCS:NFAQ:NINTRO:N*html}; do \
		${INSTALL_DATA} ${WRKSRC}/$${d} ${STAGEDIR}${DOCSDIR}; \
	done

regress: build
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} test

ckp:
	${MAKE} -DPATCH_DEBUG clean patch

# requires ftp/ncftp3
cklatest:
	@${ECHO} -n "Currently at: "
	@${MAKE} -V PATCHLEVEL
	-ncftpls \
		${PATCH_SITES:Mftp*:Ox:[1]} \
		| fgrep -v .sig | ${TAIL}

.include <bsd.port.mk>
