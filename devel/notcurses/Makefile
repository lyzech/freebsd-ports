# $FreeBSD$

PORTNAME=	notcurses
DISTVERSIONPREFIX=	v
DISTVERSION=	${ABIVERSION}.7.0
CATEGORIES=	devel

MAINTAINER=	nickblack@linux.com
COMMENT=	TUI library for modern terminal emulators

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libqrcodegen.so:graphics/qr-code-generator \
		libunistring.so:devel/libunistring

USES=		cmake:noninja compiler:c++17-lang localbase ncurses:port pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dankamongmen
USE_LDCONFIG=	yes

ABIVERSION=	1

PLIST_SUB=	REL_VER=${DISTVERSION} ABI_VER=${ABIVERSION}

TEST_TARGET=	test

OPTIONS_DEFINE=		DOCS
OPTIONS_SUB=		yes

DOCS_CMAKE_BOOL=	USE_PANDOC USE_DOCTEST
DOCS_BUILD_DEPENDS=	${LOCALBASE}/include/doctest/doctest.h:devel/doctest \
			pandoc:textproc/hs-pandoc

PORTDOCS=	*.md

.include <bsd.port.mk>
