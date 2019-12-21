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
 * File:   instance_array.h
 * Author:
 *
 * Created on December 14, 2019, 10:03 PM
 */

#ifndef INSTANCE_ARRAY_H
#define INSTANCE_ARRAY_H

namespace UHDM {

  class instance_array : public BaseClass {
  public:
    instance_array(){}
    ~instance_array() final {}
    
    BaseClass* get_vpiParent() const { return vpiParent_; }

    void set_vpiParent(BaseClass* data) { vpiParent_ = data; }

    int get_uhdmParentType() const { return uhdmParentType_; }

    void set_uhdmParentType(int data) { uhdmParentType_ = data; }

  private:
    
    BaseClass* vpiParent_;

    int uhdmParentType_;

  };

  class instance_arrayFactory {
  friend Serializer;
  public:
  static instance_array* make() {
    instance_array* obj = new instance_array();
    objects_.push_back(obj);
    return obj;
  }
  private:
    static std::vector<instance_array*> objects_;
  };
 	      
  class VectorOfinstance_arrayFactory {
  friend Serializer;
  public:
  static std::vector<instance_array*>* make() {
    std::vector<instance_array*>* obj = new std::vector<instance_array*>();
    objects_.push_back(obj);
    return obj;
  }
  private:
  static std::vector<std::vector<instance_array*>*> objects_;
  };

};

#endif

