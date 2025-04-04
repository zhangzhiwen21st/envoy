#pragma once

#include "envoy/server/bootstrap_extension_config.h"

#include "gmock/gmock.h"

namespace Envoy {
namespace Server {

class MockBootstrapExtension : public BootstrapExtension {
public:
  MockBootstrapExtension();
  ~MockBootstrapExtension() override;

  MOCK_METHOD(void, onServerInitialized, (), (override));
  MOCK_METHOD(void, onWorkerThreadInitialized, (), (override));
};

namespace Configuration {
class MockBootstrapExtensionFactory : public BootstrapExtensionFactory {
public:
  MockBootstrapExtensionFactory();
  ~MockBootstrapExtensionFactory() override;

  MOCK_METHOD(BootstrapExtensionPtr, createBootstrapExtension,
              (const Protobuf::Message&, Configuration::ServerFactoryContext&), (override));
  MOCK_METHOD(ProtobufTypes::MessagePtr, createEmptyConfigProto, (), (override));
  MOCK_METHOD(std::string, name, (), (const, override));
};
} // namespace Configuration
} // namespace Server
} // namespace Envoy
