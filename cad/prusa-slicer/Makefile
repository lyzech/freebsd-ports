# $FreeBSD$

PORTNAME=	prusa-slicer
DISTVERSION=	2.2.0-alpha2
CATEGORIES=	cad

COMMENT=	G-code generator for 3D printers

USE_GITHUB=	yes
GH_ACCOUNT=	prusa3d
GH_PROJECT=	PrusaSlicer
DISTVERSIONPREFIX=	version_

GH_TUPLE=	libusb:hidapi:7da5cc9:hidapi

USES=		cmake compiler:c++17-lang eigen:3 iconv:wchar_t pkgconfig
USE_WX=		3.1

BUILD_DEPENDS=	googletest>0:devel/googletest \
		${LOCALBASE}/include/cereal/access.hpp:devel/cereal \
		${LOCALBASE}/lib/libhidapi.a:comms/hidapi

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libnlopt.so:math/nlopt \
		libtbb.so:devel/tbb
USE_GL=		glew

CMAKE_ON=	SLIC3R_FHS
CMAKE_OFF=	SLIC3R_PCH
CMAKE_ARGS=	-DSLIC3R_GTK=3 \
		-DwxWidgets_CONFIG_EXECUTABLE:STRING=${WX_CONFIG}

post-extract:
	@${MV} ${WRKSRC_hidapi}/libusb ${WRKSRC}/src/hidapi

.include <bsd.port.mk>
