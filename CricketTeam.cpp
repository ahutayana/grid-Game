#include "CricketTeam.h"
//good!
CricketTeam::CricketTeam()
{
	head = nullptr;
	tail = nullptr;
	listSize = 0;
}
//good!
CricketTeam::CricketTeam(const CricketTeam& rhs)
{
	head = nullptr;
	tail = nullptr;
	listSize = 0;

	Node* p = rhs.head;
	while (p != nullptr)
	{
		addCricketer(p->m_firstName, p->m_lastName, p->m_value);
		p = p->next;
	}
}
//good!
CricketTeam::~CricketTeam()
{
	Node* p = head;
	while (p != nullptr)
	{
		Node* t = p->next;
		delete p;
		p = t;
	}
}
//good!
const CricketTeam& CricketTeam::operator=(const CricketTeam& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	Node* p = head;
	while (p != nullptr)
	{
		Node* t = p->next;
		delete p;
		p = t;
		break;
	}
	head = nullptr;
	tail = nullptr;
	listSize = 0;

	Node* j = rhs.head;
	while (j != nullptr)
	{
		addCricketer(j->m_firstName, j->m_lastName, j->m_value);
		j = j->next;
	}
	return *this;
}
//good!
bool CricketTeam::noTeam() const
{
	if (head == nullptr)
	{
		return true;
	}
	return false;
}
//good!
int CricketTeam::cricketerCount() const
{
	return listSize;
}
//good!
bool CricketTeam::addCricketer(const std::string& firstName, const std::string& lastName, const CricketType& value)
{
	Node* player = new Node;
	player->m_firstName = firstName;
	player->m_lastName = lastName;
	player->m_value = value;

	Node* p = head;
	while (p == nullptr)//adds player if list is empty
	{
		head = player;
		tail = player;
		head->prev = nullptr;
		tail->next = nullptr;
		++listSize;
		return true;
	}
	while (p != nullptr)//return false if player full name matches current player in list
	{
		if (p->m_firstName == firstName && p->m_lastName == lastName)
		{
			return false;
		}
		if (p->next == nullptr)//if at last player and still no match then break out of loop
		{
			break;
		}
		p = p->next;
	}
	p = head;//set pointer back to first player
	while (p != nullptr)//iterates through list
	{
		if (p->m_lastName > lastName && p == head)
		{
			
			player->prev = p->prev;
			player->next = p;
			p->prev = player;
			head = player;
			++listSize;
			return true;
		}
		else if (p->m_lastName < lastName && p == tail)
		{
			player->next = p->next;
			player->prev = p;
			p->next = player;
			tail = player;
			++listSize;
			return true;
		}
		else if (p->m_lastName < lastName && p->next != nullptr && p->next->m_lastName > lastName)
		{
			player->next = p->next;
			player->prev = p;
			p->next = player;
			p->next->prev = player;
			++listSize;
			return true;
		}
		else if (p->m_lastName == lastName && p->m_firstName > firstName && p == head)
		{

			player->prev = p->prev;
			player->next = p;
			p->prev = player;
			head = player;
			++listSize;
			return true;
		}
		else if (p->m_lastName == lastName && p->m_firstName < firstName && p == tail)
		{
			player->next = p->next;
			player->prev = p;
			p->next = player;
			tail = player;
			++listSize;
			return true;
		}
		else if (p->m_lastName == lastName && p->m_firstName < firstName && p->next != nullptr && p->next->m_firstName > firstName)
		{
			player->next = p->next;
			player->prev = p;
			p->next = player;
			p->next->prev = player;
			++listSize;
			return true;
		}
		p = p->next;
	}
	return true;
}
//good!
bool CricketTeam::substituteCricketer(const std::string& firstName, const std::string& lastName, const CricketType& value)
{
	Node* p = head;
	while (p != nullptr)//return true if player full name matches current player in list
	{
		if (p->m_firstName == firstName && p->m_lastName == lastName)
		{
			p->m_value = value;
			return true;
		}
		if (p->next == nullptr)//if at last player and still no match then break out of loop
		{
			break;
		}
		p = p->next;
	}
	return false;
}
//good!
bool CricketTeam::addOrSubstitute(const std::string& firstName, const std::string& lastName, const CricketType& value)
{
	Node* p = head;
	while (p != nullptr)//return true if player full name matches current player in list
	{
		if (p->m_firstName == firstName && p->m_lastName == lastName)
		{
			p->m_value = value;
			return true;
		}
		if (p->next == nullptr)//if at last player and still no match then break out of loop
		{
			break;
		}
		p = p->next;
	}
	addCricketer(firstName, lastName, value);
	return true;
}
//good!
bool CricketTeam::releaseCricketer(const std::string& firstName, const std::string& lastName)
{
	Node* p = head;
	while (p != nullptr)//return true if player full name matches current player in list
	{
		if (p->m_firstName == firstName && p->m_lastName == lastName)
		{
			Node* k = head;
			Node* t = tail;
			if (p == k)
			{
				k = p->next;
				k->prev = nullptr;
			}
			else if (p != k && p != t)
			{
				p->next->prev = p->prev;
				p->prev->next = p->next;
			}
			else if (p == t)
			{
				t = p->prev;
				t->next = nullptr;
			}
			delete p;
			--listSize;
			return true;
		}
		if (p->next == nullptr)//if at last player and still no match then break out of loop
		{
			break;
		}
		p = p->next;
	}
	return false;
}
//good!
bool CricketTeam::rosteredOnCricketTeam(const std::string& firstName, const std::string& lastName) const
{
	Node* p = head;
	while (p != nullptr)//return true if player full name matches current player in list
	{
		if (p->m_firstName == firstName && p->m_lastName == lastName)
		{
			return true;
		}
		if (p->next == nullptr)//if at last player and still no match then break out of loop
		{
			break;
		}
		p = p->next;
	}
	return false;
}
//good!
bool CricketTeam::searchForCricketer(const std::string& firstName, const std::string& lastName, CricketType& value) const
{
	Node* p = head;
	while (p != nullptr)//return true if player full name matches current player in list
	{
		if (p->m_firstName == firstName && p->m_lastName == lastName)
		{
			value = p->m_value;
			return true;
		}
		if (p->next == nullptr)//if at last player and still no match then break out of loop
		{
			break;
		}
		p = p->next;
	}
	return false;
}
//good!
bool CricketTeam::checkTeamForCricketer(int i, std::string& firstName, std::string& lastName, CricketType& value) const
{
	Node* p = head;
	int playerCount = 0;
	if (i < listSize && i >= 0)
	{
		while (playerCount != i)
		{
			++playerCount;
			p = p->next;
		}
		firstName = p->m_firstName;
		lastName = p->m_lastName;
		value = p->m_value;
		return true;
	}
	return false;
}
//good!
void CricketTeam::tradeCricketTeams(CricketTeam& other)
{
	Node* p = head;
	head = other.head;
	other.head = p;
}
//good!
bool mergeCricketers(const CricketTeam& odOne, const CricketTeam& odTwo, CricketTeam& odJoined)
{
	bool sameValue = true;
	int countTwo = 0;
	while (countTwo < odTwo.cricketerCount())
	{
		std::string odTwoFirstName;
		std::string odTwoLastName;
		CricketType odTwoValue;
		CricketType odOneValue;
		odTwo.checkTeamForCricketer(countTwo, odTwoFirstName, odTwoLastName, odTwoValue);
		if (odOne.rosteredOnCricketTeam(odTwoFirstName, odTwoLastName) == false)
		{
			odJoined.addCricketer(odTwoFirstName, odTwoLastName, odTwoValue);
		}
		if (odOne.rosteredOnCricketTeam(odTwoFirstName, odTwoLastName) == true)
		{
			odOne.searchForCricketer(odTwoFirstName, odTwoLastName, odOneValue);
			if (odTwoValue == odOneValue)
			{
				odJoined.addCricketer(odTwoFirstName, odTwoLastName, odTwoValue);
			}
			if (odTwoValue != odOneValue)
			{
				sameValue = false;
			}
		}
		++countTwo;
	}
	int countOne = 0;
	while (countOne < odOne.cricketerCount())
	{
		std::string odOneFirstName;
		std::string odOneLastName;
		CricketType odOneValue;
		odOne.checkTeamForCricketer(countOne, odOneFirstName, odOneLastName, odOneValue);
		if (odTwo.rosteredOnCricketTeam(odOneFirstName, odOneLastName) == false)
		{
			odJoined.addCricketer(odOneFirstName, odOneLastName, odOneValue);
		}
		++countOne;
	}
	return sameValue;
}
//good!
void checkCricketers(const std::string& fsearch, const std::string& lsearch, const CricketTeam& odOne, CricketTeam& odResult)
{
	int count = 0;
	while (count < odOne.cricketerCount())
	{
		std::string odOneFirstName;
		std::string odOneLastName;
		CricketType odOneValue;
		odOne.checkTeamForCricketer(count, odOneFirstName, odOneLastName, odOneValue);
		if (fsearch == odOneFirstName && lsearch == odOneLastName)
		{
			odResult.addCricketer(odOneFirstName, odOneLastName, odOneValue);
		}
		else if (fsearch == "*" && lsearch == "*")
		{
			odResult.addCricketer(odOneFirstName, odOneLastName, odOneValue);
		}
		else if (fsearch == odOneFirstName && lsearch == "*")
		{
			odResult.addCricketer(odOneFirstName, odOneLastName, odOneValue);
		}
		else if (fsearch == "*" && lsearch == odOneLastName)
		{
			odResult.addCricketer(odOneFirstName, odOneLastName, odOneValue);
		}
		++count;
	}
}