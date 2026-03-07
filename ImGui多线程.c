//逸晨自写优化多线程
#include <pthread.h>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>


std::mutex 任务互斥锁;
std::condition_variable 任务条件;
bool 任务判断 = false;

void* hook_dlsym(void* handle, const char* name)
{
if (strstr((const char *) name, oxorany("__memcpy_chk")) ||
strstr((const char *) name, oxorany("ptrace")) ||
strstr((const char *) name, oxorany("mprotect")) ||
strstr((const char *) name, oxorany("mmap"))) {
return 0;
}
return dlsym(handle, name);
} //imp.dlsym

//4.2 Function: sym.imp.dlsym, Addr: 0x51fc00, Size: 16, BBs: 1, Signature: sym.imp.dlsym ();


void 获取so进程() {
while (!UE4) {
UE4 = Tools::GetBaseAddress("libUE4.so");
std::this_thread::sleep_for(std::chrono::seconds(1));
}
while (!anort) {
anort = Tools::GetBaseAddress("libanort.so");
std::this_thread::sleep_for(std::chrono::seconds(1));
}
while (!anogs) {
anogs = Tools::GetBaseAddress("libanogs.so");
std::this_thread::sleep_for(std::chrono::seconds(1));
PATCH_LIB("libanogs.so", "0x468d14","C0 03 5F D6");//容器防闪
PATCH_LIB("libanogs.so", "0x213360 + 0x8", "C0 03 5F D6");//防闪
}
while (!TDataMaster) {
TDataMaster = Tools::GetBaseAddress("libTDataMaster.so");
std::this_thread::sleep_for(std::chrono::seconds(1));
}
while (!gcloud) {
gcloud = Tools::GetBaseAddress("libgcloud.so");
std::this_thread::sleep_for(std::chrono::seconds(1));
}

}

void 初始化线程() {
std::unique_lock<std::mutex> lock(任务互斥锁);
任务条件.wait(lock, [] { return 任务判断; });

while (!g_App) {
g_App = *(android_app **)(UE4 + GNativeAndroidApp_Offset);
std::this_thread::sleep_for(std::chrono::seconds(1));
}
FName::GNames = GetGNames();
while (!FName::GNames) {
FName::GNames = GetGNames();
std::this_thread::sleep_for(std::chrono::seconds(1));
}
UObject::GUObjectArray = (FUObjectArray *)(UE4 + GUObject_Offset);

        system("adb shell am compat disable BLOCK_UNTRUSTED_TOUCHES com.tencent.ig");
        system("adb shell am compat disable BLOCK_UNTRUSTED_TOUCHES com.pubg.krmobile");
        system("adb shell am compat disable BLOCK_UNTRUSTED_TOUCHES com.rekoo.pubgm");
        system("adb shell am compat disable BLOCK_UNTRUSTED_TOUCHES com.vng.pubgmobile");
        system("adb shell am compat disable BLOCK_UNTRUSTED_TOUCHES com.pubg.imobile");

}

void 获取资源线程() {
std::unique_lock<std::mutex> lock(任务互斥锁);
任务条件.wait(lock, [] { return 任务判断; });
}

/* -------------------- 设置Hook线程 -------------------- */
void 设置Hook线程() {
std::unique_lock<std::mutex> lock(任务互斥锁);
任务条件.wait(lock, [] { return 任务判断; });

shadowhook_init(shadowhook_mode_t::SHADOWHOOK_MODE_UNIQUE, 0); //初始化

shadowhook_hook_func_addr((void *)(anogs + oxorany(0x51fc00)), (void *)hook_dlsym, nullptr); //线程初始化 函数:sym.imp.dlsym so:libanogs.so

shadowhook_hook_sym_name("libEGL.so", "eglSwapBuffers", (void *)_eglSwapBuffers, (void **)&orig_eglSwapBuffers); //egl菜单初始化 函数:sym.imp.eglSwapBuffers so:libUE4.so

}

__attribute__((constructor)) void 逸晨线程() {
//启动so基址加载线程
std::thread([]() {
获取so进程();
{
std::lock_guard<std::mutex> lock(任务互斥锁);
任务判断 = true;
}
任务条件.notify_all();
}).detach();

//创建工作线程(初始化 获取资源 设置Hook)
std::thread(初始化线程).detach();
std::thread(获取资源线程).detach();
std::thread(设置Hook线程).detach();

}