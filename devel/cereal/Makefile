# $FreeBSD$

PORTNAME=	cereal
PORTVERSION=	1.2.2
CATEGORIES=	devel

COMMENT=	C++11 library for serialization

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/variant.hpp:devel/boost-libs

USES=           cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	USCiLab
GH_TAGNAME=     v${PORTVERSION}

CMAKE_ON=	SKIP_PORTABILITY_TEST THREAD_SAFE
CMAKE_OFF=	WITH_WERROR

.include <bsd.port.mk>
