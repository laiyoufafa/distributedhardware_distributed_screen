/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "configdistributedhardware_fuzzer.h"

#include <cstddef>
#include <cstdint>

#include "dscreen_source_handler.h"

namespace OHOS {
namespace DistributedHardware {
void ConfigDistributedHardwareFuzzTest(const uint8_t* data, size_t size)
{
    if ((data == nullptr) || (size <= 0)) {
        return;
    }

    std::string devId(reinterpret_cast<const char*>(data), size);
    std::string dhId(reinterpret_cast<const char*>(data), size);
    std::string key(reinterpret_cast<const char*>(data), size);
    std::string value(reinterpret_cast<const char*>(data), size);

    DScreenSourceHandler::GetInstance().ConfigDistributedHardware(devId, dhId, key, value);
}
}
}

/* Fuzzer entry point */
extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
{
    /* Run your code on data */
    OHOS::DistributedHardware::ConfigDistributedHardwareFuzzTest(data, size);
    return 0;
}