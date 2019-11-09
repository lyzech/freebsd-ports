# $FreeBSD$

PORTNAME=	prusa-slicer
PORTVERSION=	2.1.0
CATEGORIES=	cad

COMMENT=	G-code generator for 3D printers

USE_GITHUB=	yes
GH_ACCOUNT=	prusa3d
GH_PROJECT=	PrusaSlicer
GH_TAGNAME=	version_${PORTVERSION}

USES=		cmake compiler:c++11-lang eigen:3
USE_WX=		3.1

BUILD_DEPENDS=	googletest>0:devel/googletest \
		${LOCALBASE}/include/cereal/access.hpp:devel/cereal

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libnlopt.so:math/nlopt \
		libtbb.so:devel/tbb
USE_GL=		glew

CMAKE_ON=	SLIC3R_FHS
CMAKE_OFF=	SLIC3R_PCH
CMAKE_ARGS=	-DSLIC3R_GTK=3 \
		-DwxWidgets_CONFIG_EXECUTABLE:STRING=${WX_CONFIG}

.include <bsd.port.mk>
