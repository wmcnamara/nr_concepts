#pragma once
#include <type_traits>
#include <algorithm> //std::swap

namespace concepts
{
	/*
		Basic
		https://en.cppreference.com/w/cpp/named_req#Basic
	*/

	//specifies that an object of the type can be default constructed 
	template<typename T>
	concept DefaultConstructible = std::is_default_constructible<T>::value;

	//specifies that an object of the type can be constructed from rvalue 
	template<typename T>
	concept MoveConstructible = std::is_move_constructible<T>::value;

	//specifies that an object of the type can be constructed from lvalue 
	template<typename T>
	concept CopyConstructible = std::is_copy_constructible<T>::value;

	//specifies that an object of the type can be assigned from rvalue 
	template<typename T>
	concept MoveAssignable = std::is_move_assignable<T>::value;

	//specifies that an object of the type can be assigned from lvalue
	template<typename T>
	concept CopyAssignable = std::is_copy_assignable<T>::value;

	//specifies that an object of the type can be destroyed 
	template<typename T>
	concept Destructible = std::is_destructible<T>::value;


	/*
		Type properties
		https://en.cppreference.com/w/cpp/named_req#Type_properties
	*/

	//class with trivial copy, assignment and destructor 
	template<typename T>
	concept TriviallyCopyable = std::is_trivially_copyable<T>::value;

	//class with trivial constructors, assignment and destructor 
	template<typename T>
	concept TrivialType = std::is_trivial<T>::value;

	//non-virtual class containing only other StandardLayout members, all with the same access control 
	template<typename T>
	concept StandardLayoutType = std::is_standard_layout<T>::value;

	//POD (Plain Old Data) structure, compatible with C struct 
	template<typename T>
	concept PODType = std::is_pod<T>::value;


	/*
		Library-wide
		https://en.cppreference.com/w/cpp/named_req#Library-wide
	*/

	//operator== is an equivalence relation
	template<typename T>
	concept EqualityComparable = requires(T t, T i) { t == i; };

	//operator< is a strict weak ordering relation
	template<typename T>
	concept LessThanComparable = requires(T t, T i) { t < i; };

	//can be swapped with an unqualified non-member function call swap()
	template<typename T>
	concept Swappable = (requires(T t, T i) { swap(t, i); } || requires(T t, T i) { std::swap(t, i); }) && MoveConstructible<T> && MoveAssignable<T>;
}