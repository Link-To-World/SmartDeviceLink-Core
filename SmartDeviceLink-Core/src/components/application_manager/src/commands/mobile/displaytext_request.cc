/*

 Copyright (c) 2013, Ford Motor Company
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following
 disclaimer in the documentation and/or other materials provided with the
 distribution.

 Neither the name of the Ford Motor Company nor the names of its contributors
 may be used to endorse or promote products derived from this software
 without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
 */

#include <string.h>
#include "application_manager/commands/mobile/displaytext_request.h"
#include "application_manager/application_manager_impl.h"
#include "application_manager/application_impl.h"
#include "application_manager/message_helper.h"
#include "interfaces/MOBILE_API.h"

//Huaguoping-Add-20150901
namespace application_manager {

namespace commands {

DisplayTextRequest::DisplayTextRequest(const MessageSharedPtr& message): CommandRequestImpl(message) {}

DisplayTextRequest::~DisplayTextRequest() {}

bool DisplayTextRequest::Init() 
{
	return true;
}

void DisplayTextRequest::Run() 
{
	LOG4CXX_AUTO_TRACE(logger_);

	ApplicationSharedPtr application = ApplicationManagerImpl::instance()->application(connection_key());

	if(!application) 
	{
		SendResponse(false, mobile_apis::Result::APPLICATION_NOT_REGISTERED);
		LOG4CXX_ERROR(logger_, "Application is not registered");
		return;
	}

	(*message_)[strings::params][strings::message_type] = application_manager::MessageType::kResponse;
	
	SendResponse(true, mobile_apis::Result::SUCCESS, "Made in Ekai!");
}

}  // namespace commands
}  // namespace application_manager
//Huaguoping-Add-20150901
