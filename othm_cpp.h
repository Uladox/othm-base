
#define OTHM_CPP_FIRST(A, ...) A
#define OTHM_CPP_SECOND(A, B, ...) B

#define OTHM_CPP_CAT(A, B) A ## B

#define OTHM_CPP_IF_ELSE(CONDITION)			\
	OTHM_CPP_IF_ELSE_BETA(OTHM_CPP_BOOL(CONDITION))
#define OTHM_CPP_IF_ELSE_BETA(CONDITION)	\
	OTHM_CPP_CAT(OTHM_CPP_IF_, CONDITION)

#define OTHM_CPP_IF_1(...) __VA_ARGS__ OTHM_CPP_IF_1_ELSE
#define OTHM_CPP_IF_0(...)             OTHM_CPP_IF_0_ELSE

#define OTHM_CPP_IF_1_ELSE(...)
#define OTHM_CPP_IF_0_ELSE(...) __VA_ARGS__

#define OTHM_CPP_PROBE() ~, 1

#define OTHM_CPP_IS_PROBE(...) OTHM_CPP_SECOND(__VA_ARGS__, 0)

#define OTHM_CPP_NOT(X)						\
	OTHM_CPP_IS_PROBE(OTHM_CPP_CAT(OTHM_CPP_NOT_, X))
#define OTHM_CPP_NOT_0 OTHM_CPP_PROBE()

#define OTHM_CPP_BOOL(x) OTHM_CPP_NOT(OTHM_CPP_NOT(x))

#define OTHM_CPP_EMPTY()

#define OTHM_CPP_EVAL(...) OTHM_CPP_EVAL1024(__VA_ARGS__)
#define OTHM_CPP_EVAL1024(...) OTHM_CPP_EVAL512(OTHM_CPP_EVAL512(__VA_ARGS__))
#define OTHM_CPP_EVAL512(...) OTHM_CPP_EVAL256(OTHM_CPP_EVAL256(__VA_ARGS__))
#define OTHM_CPP_EVAL256(...) OTHM_CPP_EVAL128(OTHM_CPP_EVAL128(__VA_ARGS__))
#define OTHM_CPP_EVAL128(...) OTHM_CPP_EVAL64(OTHM_CPP_EVAL64(__VA_ARGS__))
#define OTHM_CPP_EVAL64(...) OTHM_CPP_EVAL32(OTHM_CPP_EVAL32(__VA_ARGS__))
#define OTHM_CPP_EVAL32(...) OTHM_CPP_EVAL16(OTHM_CPP_EVAL16(__VA_ARGS__))
#define OTHM_CPP_EVAL16(...) OTHM_CPP_EVAL8(OTHM_CPP_EVAL8(__VA_ARGS__))
#define OTHM_CPP_EVAL8(...) OTHM_CPP_EVAL4(OTHM_CPP_EVAL4(__VA_ARGS__))
#define OTHM_CPP_EVAL4(...) OTHM_CPP_EVAL2(OTHM_CPP_EVAL2(__VA_ARGS__))
#define OTHM_CPP_EVAL2(...) OTHM_CPP_EVAL1(OTHM_CPP_EVAL1(__VA_ARGS__))
#define OTHM_CPP_EVAL1(...) __VA_ARGS__

#define OTHM_CPP_DEFER1(m) \
	m OTHM_CPP_EMPTY()
#define OTHM_CPP_DEFER2(m) \
	m OTHM_CPP_EMPTY OTHM_CPP_EMPTY()()
#define OTHM_CPP_DEFER3(m) \
	m OTHM_CPP_EMPTY OTHM_CPP_EMPTY OTHM_CPP_EMPTY()()()
#define OTHM_CPP_DEFER4(m) \
	m OTHM_CPP_EMPTY OTHM_CPP_EMPTY OTHM_CPP_EMPTY OTHM_CPP_EMPTY	\
	()()()()

#define OTHM_CPP_HAS_ARGS(...)						\
	OTHM_CPP_BOOL							\
	(OTHM_CPP_FIRST(OTHM_CPP_END_OF_ARGUMENTS_ __VA_ARGS__)())
#define OTHM_CPP_END_OF_ARGUMENTS_() 0

#define OTHM_CPP_MAP(M, FIRST, ...)					\
	M(FIRST)							\
	OTHM_CPP_IF_ELSE(OTHM_CPP_HAS_ARGS(__VA_ARGS__))		\
  	  (OTHM_CPP_DEFER2(OTHM_CPP_MAP_BETA) () (M, __VA_ARGS__))	\
	  ()
#define OTHM_CPP_MAP_BETA() OTHM_CPP_MAP

#define GREET(x) Hello, x!

/* OTHM_CPP_EVAL8(OTHM_CPP_MAP(GREET, world, the ilk, macro abusers, and Happy Halloween)) */