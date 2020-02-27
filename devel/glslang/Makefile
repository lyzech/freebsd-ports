# $FreeBSD$

PORTNAME=	glslang
DISTVERSION=	7.11.3214
PORTREVISION=	1
CATEGORIES=	devel graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	24b3e8384e93.patch:-p1

MAINTAINER=	greg@unrelenting.technology
COMMENT=	OpenGL and OpenGL ES shader front end and validator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKDIR}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libSPIRV-Tools-opt.a:devel/spirv-tools

USES=		cmake compiler:c++11-lib localbase

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup

post-extract:
	${SED} '/^$$/,$$d' ${WRKSRC}/${PORTNAME}/Include/Types.h \
			>${WRKDIR}/LICENSE

post-patch:
	${REINPLACE_CMD} \
		"s|SPIRV glslang SPIRV-Tools-opt|SPIRV glslang ${LOCALBASE}/lib/libSPIRV-Tools.a ${LOCALBASE}/lib/libSPIRV-Tools-opt.a|" \
		${WRKSRC}/SPIRV/CMakeLists.txt

.include <bsd.port.mk>
