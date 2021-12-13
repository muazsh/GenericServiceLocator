#pragma once
#include <map>
#include <string>
#include <memory>
#include <typeinfo>


namespace gsl
{
	class GenericServiceLocator
	{
		std::map<std::string, std::shared_ptr<void>> m_services;

		public:
			template<class T>
			void AddService(std::shared_ptr<T>& service)
			{
				m_services[typeid(T).name()] = service;
			}

			template<class T>
			std::shared_ptr<T>& GetService()
			{
				return (std::shared_ptr<T>&)m_services[typeid(T).name()];
			}

			template<class T>
			void RemoveService()
			{
				m_services.erase(typeid(T).name());
			}
	};
}
