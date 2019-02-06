# $FreeBSD$

PORTNAME=	xwayland
PORTVERSION=	1.19.1
# This is inherited from x11-servers/xorg-server
# Ensure it does not go backwards when bumping
PORTREVISION=	11

COMMENT=	X Clients under Wayland

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/wayland-protocols.pc:graphics/wayland-protocols \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libinput.so:x11/libinput

MASTERDIR=	${.CURDIR}/../xorg-server
DESCR=		${.CURDIR}/pkg-descr

SLAVE_PORT=	yes
USE_XORG=	x11 xext
USE_GL+=	egl gbm

CONFIGURE_ARGS+=--disable-dmx --disable-xephyr --disable-xnest --disable-xvfb \
		--enable-xwayland 

PLIST_FILES=	bin/Xwayland

do-install:
	cd ${WRKSRC}/hw/xwayland; DESTDIR=${STAGEDIR} ${MAKE_CMD} install

.include "${MASTERDIR}/Makefile"
