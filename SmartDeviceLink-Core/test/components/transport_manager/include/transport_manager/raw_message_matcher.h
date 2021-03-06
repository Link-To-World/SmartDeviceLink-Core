/*
 * \file raw_message_matcher.h
 * \brief matcher RawMessagePtr
 *
 * Copyright (c) 2013, Ford Motor Company
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of the Ford Motor Company nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef APPLINK_TEST_COMPONENTS_TRANSPORT_MANAGER_INCLUDE_TRANSPORT_MANAGER_RAW_MESSAGE_MATCHER_H_
#define APPLINK_TEST_COMPONENTS_TRANSPORT_MANAGER_INCLUDE_TRANSPORT_MANAGER_RAW_MESSAGE_MATCHER_H_

#include <gmock/gmock.h>

#include "transport_manager/common.h"
#include "protocol/common.h"

using ::testing::Matcher;
using ::testing::MatcherInterface;
using ::testing::MatchResultListener;

using RawMessagePtr = ::protocol_handler::RawMessagePtr;
using RawMessage = ::protocol_handler::RawMessage;

namespace test {
namespace components {
namespace transport_manager {

using namespace ::protocol_handler;

class RawMessageMatcher : public MatcherInterface<RawMessagePtr> {
 public:
  explicit RawMessageMatcher(RawMessagePtr ptr);

  virtual bool MatchAndExplain(const RawMessagePtr ptr,
                                   MatchResultListener* listener) const;
  virtual void DescribeTo(::std::ostream* os) const;
  virtual void DescribeNegationTo(::std::ostream* os) const;

 private:
  const RawMessagePtr ptr_;
};

inline const Matcher<RawMessagePtr> RawMessageEq(RawMessagePtr msg) {
  return MakeMatcher(new RawMessageMatcher(msg));
}

}  // namespace transport_manager
}  // namespace components
}  // namespace test

#endif /* APPLINK_TEST_COMPONENTS_TRANSPORT_MANAGER_INCLUDE_TRANSPORT_MANAGER_RAW_MESSAGE_MATCHER_H_ */
