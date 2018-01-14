// Object Pool

#include <vector>

class Object
{
};


class ObjectPool
{
private:
	struct PoolRecord
	{
		Object* instance;
		bool    in_use;
	};

	std::vector<PoolRecord> m_pool;

public:
	Object * createNewObject()
	{
		for (size_t i = 0; i < m_pool.size(); ++i)
		{
			if (!m_pool[i].in_use)
			{
				// set object in use and return instance
				m_pool[i].in_use = true;
				return m_pool[i].instance;
			}
		}
		// if there is not free object then expand pool
		PoolRecord record;
		record.instance = new Object;
		record.in_use = true;

		m_pool.push_back(record);

		return record.instance;
	}

	void deleteObject(Object* object)
	{
		// set object is free
		for (size_t i = 0; i < m_pool.size(); ++i)
		{
			if (m_pool[i].instance == object)
			{
				m_pool[i].in_use = false;
				break;
			}
		}
	}

	virtual ~ObjectPool()
	{
		// delete objects
		for (size_t i = 0; i < m_pool.size(); ++i)
			delete m_pool[i].instance;
	}
};