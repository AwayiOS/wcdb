/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef copy_on_write_lazy_string_list_hpp
#define copy_on_write_lazy_string_list_hpp

#include <WINQ/copy_on_write_lazy_describable.hpp>
#include <list>

class copy_on_write_lazy_string_list
    : public copy_on_write_lazy_describable<std::list<copy_on_write_string>> {
public:
    using Super =
        copy_on_write_lazy_describable<std::list<copy_on_write_string>>;

    void append(const copy_on_write_string &string);

    bool empty() const;

protected:
    virtual copy_on_write_string calculatedDescription() const override;

private:
    using Super::get_or_copy;
};

#endif /* copy_on_write_lazy_string_list_hpp */
