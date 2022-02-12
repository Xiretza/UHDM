/*
 Do not modify, auto-generated by model_gen.tcl

 Copyright 2019 Alain Dargelas

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

/*
 * File:   Serializer.cpp
 * Author:
 *
 * Created on October 4, 2021, 10:53 PM
 */
#include <uhdm/Serializer.h>

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <uhdm/uhdm.h>

#if defined(_MSC_VER)
  #pragma warning(push)
  #pragma warning(disable : 4267)  // 'var' : conversion from 'size_t' to 'type', possible loss of data
#endif

namespace UHDM {

void DefaultErrorHandler(ErrorType errType, const std::string& errorMsg, const any* object1, const any* object2) {
  std::cerr << errorMsg << std::endl;
}

void Serializer::SetId(const BaseClass* p, unsigned long id) {
  allIds_.insert(std::make_pair(p, id));
}

unsigned long Serializer::GetId(const BaseClass* p) {
  std::unordered_map<const BaseClass*, unsigned long>::iterator itr = allIds_.find(p);
  if (itr == allIds_.end()) {
    unsigned long tmp = incrId_;
    allIds_.insert(std::make_pair(p, incrId_));
    incrId_++;
    return tmp;
  } else {
    return (*itr).second;
  }
}

<UHDM_NAME_MAP>

// From uhdm_types.h
std::string VpiTypeName(vpiHandle h) {
  uhdm_handle* handle = (uhdm_handle*) h;
  BaseClass* obj = (BaseClass*) handle->object;
  return UhdmName(obj->UhdmType());
}

static constexpr unsigned int badIndex = -1;

BaseClass* Serializer::GetObject(unsigned int objectType, unsigned int index) {
  if (index == badIndex)
    return nullptr;

  switch (objectType) {
<FACTORY_OBJECT_TYPE_MAP>
  default: return nullptr;
  }
}

std::map<std::string, unsigned long> Serializer::ObjectStats() const {
  std::map<std::string, unsigned long> stats;
<FACTORY_STATS>
  return stats;
}

void Serializer::Purge() {
  allIds_.clear();
  anyVectMaker.Purge();
  symbolMaker.Purge();
  uhdm_handleMaker.Purge();
<FACTORY_PURGE>
}
}  // namespace UHDM

#if (defined(_MSC_VER) || defined(__MINGW32__) || defined(__CYGWIN__))
  #pragma warning(pop)
#endif
