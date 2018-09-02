// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: LoginServer/login.proto
#ifndef GRPC_LoginServer_2flogin_2eproto__INCLUDED
#define GRPC_LoginServer_2flogin_2eproto__INCLUDED

#include "LoginServer/login.pb.h"

#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace Login {

class LoginRPC final {
 public:
  static constexpr char const* service_full_name() {
    return "Login.LoginRPC";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status thirdparty(::grpc::ClientContext* context, const ::Login::ThirdpartyRequest& request, ::Login::ThirdpartyReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Login::ThirdpartyReply>> Asyncthirdparty(::grpc::ClientContext* context, const ::Login::ThirdpartyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Login::ThirdpartyReply>>(AsyncthirdpartyRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Login::ThirdpartyReply>> PrepareAsyncthirdparty(::grpc::ClientContext* context, const ::Login::ThirdpartyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Login::ThirdpartyReply>>(PrepareAsyncthirdpartyRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Login::ThirdpartyReply>* AsyncthirdpartyRaw(::grpc::ClientContext* context, const ::Login::ThirdpartyRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Login::ThirdpartyReply>* PrepareAsyncthirdpartyRaw(::grpc::ClientContext* context, const ::Login::ThirdpartyRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status thirdparty(::grpc::ClientContext* context, const ::Login::ThirdpartyRequest& request, ::Login::ThirdpartyReply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Login::ThirdpartyReply>> Asyncthirdparty(::grpc::ClientContext* context, const ::Login::ThirdpartyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Login::ThirdpartyReply>>(AsyncthirdpartyRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Login::ThirdpartyReply>> PrepareAsyncthirdparty(::grpc::ClientContext* context, const ::Login::ThirdpartyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Login::ThirdpartyReply>>(PrepareAsyncthirdpartyRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< ::Login::ThirdpartyReply>* AsyncthirdpartyRaw(::grpc::ClientContext* context, const ::Login::ThirdpartyRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::Login::ThirdpartyReply>* PrepareAsyncthirdpartyRaw(::grpc::ClientContext* context, const ::Login::ThirdpartyRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_thirdparty_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status thirdparty(::grpc::ServerContext* context, const ::Login::ThirdpartyRequest* request, ::Login::ThirdpartyReply* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_thirdparty : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_thirdparty() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_thirdparty() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status thirdparty(::grpc::ServerContext* context, const ::Login::ThirdpartyRequest* request, ::Login::ThirdpartyReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestthirdparty(::grpc::ServerContext* context, ::Login::ThirdpartyRequest* request, ::grpc::ServerAsyncResponseWriter< ::Login::ThirdpartyReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_thirdparty<Service > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_thirdparty : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_thirdparty() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_thirdparty() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status thirdparty(::grpc::ServerContext* context, const ::Login::ThirdpartyRequest* request, ::Login::ThirdpartyReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_thirdparty : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_thirdparty() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_thirdparty() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status thirdparty(::grpc::ServerContext* context, const ::Login::ThirdpartyRequest* request, ::Login::ThirdpartyReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestthirdparty(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_thirdparty : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_thirdparty() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::Login::ThirdpartyRequest, ::Login::ThirdpartyReply>(std::bind(&WithStreamedUnaryMethod_thirdparty<BaseClass>::Streamedthirdparty, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_thirdparty() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status thirdparty(::grpc::ServerContext* context, const ::Login::ThirdpartyRequest* request, ::Login::ThirdpartyReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status Streamedthirdparty(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::Login::ThirdpartyRequest,::Login::ThirdpartyReply>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_thirdparty<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_thirdparty<Service > StreamedService;
};

}  // namespace Login


#endif  // GRPC_LoginServer_2flogin_2eproto__INCLUDED