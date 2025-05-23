call ndk-build clean
call ndk-build TARGET_LINK=0 NDK_DEBUG=0 CONFIGURATION=StaticRelease
call ndk-build TARGET_LINK=0 NDK_DEBUG=1 CONFIGURATION=StaticDebug
rmdir /s /q libs
rmdir /s /q obj
call ndk-build clean
call ndk-build TARGET_LINK=1 NDK_DEBUG=0 CONFIGURATION=DynamicRelease
call ndk-build TARGET_LINK=1 NDK_DEBUG=1 CONFIGURATION=DynamicDebug
rmdir /s /q libs
rmdir /s /q obj
rem xcopy /y ..\..\..\..\BuildFiles\Android\arm64-v8a\StaticRelease\libA42A420FC14D43879877877F8E62028C.a %ECO_FRAMEWORK%\Eco.SE1.Lua\BuildFiles\Android\arm64-v8a\StaticRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\arm64-v8a\DynamicRelease\libA42A420FC14D43879877877F8E62028C.so %ECO_FRAMEWORK%\Eco.SE1.Lua\BuildFiles\Android\arm64-v8a\DynamicRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\armeabi\StaticRelease\libA42A420FC14D43879877877F8E62028C.a %ECO_FRAMEWORK%\Eco.SE1.Lua\BuildFiles\Android\armeabi\StaticRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\armeabi\DynamicRelease\libA42A420FC14D43879877877F8E62028C.so %ECO_FRAMEWORK%\Eco.SE1.Lua\BuildFiles\Android\armeabi\DynamicRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\armeabi-v7a\StaticRelease\libA42A420FC14D43879877877F8E62028C.a %ECO_FRAMEWORK%\Eco.SE1.Lua\BuildFiles\Android\armeabi-v7a\StaticRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\armeabi-v7a\DynamicRelease\libA42A420FC14D43879877877F8E62028C.so %ECO_FRAMEWORK%\Eco.SE1.Lua\BuildFiles\Android\armeabi-v7a\DynamicRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\mips\StaticRelease\libA42A420FC14D43879877877F8E62028C.a %ECO_FRAMEWORK%\Eco.SE1.Lua\BuildFiles\Android\mips\StaticRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\mips\DynamicRelease\libA42A420FC14D43879877877F8E62028C.so %ECO_FRAMEWORK%\Eco.SE1.Lua\BuildFiles\Android\mips\DynamicRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\mips64\StaticRelease\libA42A420FC14D43879877877F8E62028C.a %ECO_FRAMEWORK%\Eco.SE1.Lua\BuildFiles\Android\mips64\StaticRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\mips64\DynamicRelease\libA42A420FC14D43879877877F8E62028C.so %ECO_FRAMEWORK%\Eco.SE1.Lua\BuildFiles\Android\mips64\DynamicRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\x86\StaticRelease\libA42A420FC14D43879877877F8E62028C.a %ECO_FRAMEWORK%\Eco.SE1.Lua\BuildFiles\Android\x86\StaticRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\x86\DynamicRelease\libA42A420FC14D43879877877F8E62028C.so %ECO_FRAMEWORK%\Eco.SE1.Lua\BuildFiles\Android\x86\DynamicRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\x86_64\StaticRelease\libA42A420FC14D43879877877F8E62028C.a %ECO_FRAMEWORK%\Eco.SE1.Lua\BuildFiles\Android\x86_64\StaticRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\x86_64\DynamicRelease\libA42A420FC14D43879877877F8E62028C.so %ECO_FRAMEWORK%\Eco.SE1.Lua\BuildFiles\Android\x86_64\DynamicRelease\
pause
