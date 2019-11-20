# $FreeBSD$

PORTNAME=	arcus
PORTVERSION=	${CURAVERSION}
CATEGORIES=	devel

COMMENT=	Communication library between internal components for Ultimaker software

USE_GITHUB=	yes
GH_ACCOUNT=	${CURA_GH_ACCOUNT}
GH_PROJECT=	libArcus

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		cmake compiler:c++11-lang
CMAKE_OFF=	BUILD_PYTHON

.include "${.CURDIR:H:H}/cad/cura/Makefile.common"

.include <bsd.port.mk>
