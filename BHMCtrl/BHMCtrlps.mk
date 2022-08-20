
BHMCtrlps.dll: dlldata.obj BHMCtrl_p.obj BHMCtrl_i.obj
	link /dll /out:BHMCtrlps.dll /def:BHMCtrlps.def /entry:DllMain dlldata.obj BHMCtrl_p.obj BHMCtrl_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del BHMCtrlps.dll
	@del BHMCtrlps.lib
	@del BHMCtrlps.exp
	@del dlldata.obj
	@del BHMCtrl_p.obj
	@del BHMCtrl_i.obj
