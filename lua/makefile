3ds-luajit:
	$(MAKE) -C luajit/src clean
	$(MAKE) -C luajit/src \
		HOST_CC="gcc -m32" \
		BUILDMODE=static \
		XCFLAGS=-DLUAJIT_USE_SYSMALLOC \
		CROSS=arm-none-eabi- \
		TARGET_CFLAGS="-march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft -O2 -mword-relocations -ffunction-sections -fdata-sections" \
		libluajit.a
	mkdir -p platform/luajit/3ds/
	mv luajit/src/libluajit.a platform/luajit/3ds/
	cp luajit/src/lua.h luajit/src/lua.hpp luajit/src/luajit.h luajit/src/lualib.h luajit/src/lauxlib.h luajit/src/luaconf.h platform/luajit/3ds/

switch-luajit:
	$(MAKE) -C luajit/src clean
	$(MAKE) -C luajit/src \
		HOST_CC="gcc" \
		BUILDMODE=static \
		XCFLAGS="-DLUAJIT_USE_SYSMALLOC -DLUAJIT_DISABLE_JIT" \
		CROSS=aarch64-none-elf- \
		TARGET_CFLAGS="-march=armv8-a+crc+crypto -mtune=cortex-a57 -mtp=soft -fPIC -ftls-model=local-exec -O2 -ffunction-sections -fdata-sections" \
		libluajit.a
	mkdir -p platform/luajit/switch/
	mv luajit/src/libluajit.a platform/luajit/switch/
	cp luajit/src/lua.h luajit/src/lua.hpp luajit/src/luajit.h luajit/src/lualib.h luajit/src/lauxlib.h luajit/src/luaconf.h platform/luajit/switch/

3ds-lua:
	$(MAKE) -C lua51 clean
	$(MAKE) -C lua51 \
		CC=arm-none-eabi-gcc \
		AR="arm-none-eabi-ar rcu" \
		RANLIB=arm-none-eabi-ranlib \
		CFLAGS="-march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft -O2 -mword-relocations -ffunction-sections -fdata-sections" \
		liblua.a
		LDFLAGS="" LIBS="" HOST_CFLAGS="" HOST_LIBS="" HOST_LDFLAGS=""
	mkdir -p platform/lua51/3ds/
	mv lua51/liblua.a platform/lua51/3ds/
	cp lua51/lua.h lua51/lua.hpp lua51/luajit.h lua51/lualib.h lua51/lauxlib.h lua51/luaconf.h platform/lua51/3ds
