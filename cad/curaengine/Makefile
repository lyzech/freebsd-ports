# $FreeBSD$

PORTNAME=	curaengine
PORTVERSION=	${CURAVERSION}
CATEGORIES=	cad

COMMENT=	Engine for processing 3D models into 3D printing instruction

USE_GITHUB=	yes
GH_ACCOUNT=	${CURA_GH_ACCOUNT}
GH_PROJECT=	CuraEngine
GH_TUPLE=	nothings:stb:f67165c:stb/stb

BUILD_DEPENDS=	rapidjson>0:devel/rapidjson
LIB_DEPENDS=	libArcus.so:devel/arcus \
		libpolyclipping.so:graphics/polyclipping

USES=		cmake compiler:c++11-lang pkgconfig

CMAKE_ON=	USE_SYSTEM_LIBS

.include "${.CURDIR:H:H}/cad/cura/Makefile.common"

.include <bsd.port.mk>
