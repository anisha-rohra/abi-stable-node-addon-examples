#include <napi.h>
#include <uv.h>
#include "myobject.h"

Napi::Object CreateObject(const Napi::CallbackInfo& info) {
  return MyObject::NewInstance(info.Env(), info[0]);
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  
  Napi::Object new_exports = Napi::Function::New(env, CreateObject);
  
  return new_exports;
}

NODE_API_MODULE(addon, InitAll)
