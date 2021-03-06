# Named Requirement Concepts
This repository provides concepts and constraints for C++'s standard named requirements.

Implemented concepts attempt to be fully standard compliant, and are documented within the code.

If your project uses a lot of templates, these can be incredibly useful to provide easy constraints for your template 
parameters, and improve error messages if a user gives a template an incompatible type.

It is meant as a companion to the standard concepts header.
# Usage
All of the concepts are contained in the *nr_concepts* namespace, and follow the exact same
naming conventions as specified in the official C++ standard.

Example:
```cpp
using namespace nr_concepts;

//T must meet the swappable named requirement
//https://en.cppreference.com/w/cpp/named_req/Swappable
template<Swappable T>
void swapSomething(T& a, T&, b) 
{
    std::swap(a, b);
}
```

## Currently Implemented Concepts
### Basic
 - DefaultConstructible
 - MoveConstructible
 - CopyConstructible
 - MoveAssignible
 - CopyAssignible
 - Destructible

### Type Properties
 - TriviallyCopyable
 - TrivialType
 - StandardLayourType
 - PODType

### Library Wide
 - EqualityComparable
 - LessThanCompareable
 - Swappable
 - NullablePointer
 
## Contributing
Thank you for wanting to contribute!

If you want to add a concept to the library, feel free to submit a PR with the change.
The concept should be defined in the concepts.h file, and follow this general format:

```cpp
//Description (preferably from cppreference)
template<typename T>
concept NamedRequirement = someConcept;
```
Please check the other concepts before submitting a PR to get the best idea of how to properly submit a formatted concept.

You should also add it to the README.md file as a bullet point, similar to other concepts.