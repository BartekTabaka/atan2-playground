#pragma once
#include <unordered_map>
#include <memory>
#include <stdexcept>
#include <string>

template<typename ResourceType, typename Identifier>
class ResourceManager {
public:
	void load(Identifier id, const std::string& fileName)
	{
		auto resource = std::make_unique<ResourceType>();
		if (!resource->loadFromFile(fileName))
			throw std::runtime_error("ResourceManager: failed to load: " + fileName);

		auto [it, inserted] = m_Resources.emplace(id, std::move(resource));
		if (!inserted)
			throw std::logic_error("ResourceManager: duplicate resource ID");
	}

	ResourceType& get(Identifier id)
	{
		auto found = m_Resources.find(id);
		if (found == m_Resources.end())
			throw std::runtime_error("ResourceManager: resource with the specified ID not found");

		return *found->second;
	}

	const ResourceType& get(Identifier id) const
	{
		return const_cast<ResourceManager*>(this)->get(id);
	}
private:
	std::unordered_map<Identifier, std::unique_ptr<ResourceType>> m_Resources;
};
