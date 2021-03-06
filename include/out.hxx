#if not defined BEASTHTTP_OUT_HXX
#define BEASTHTTP_OUT_HXX

#include "base/display.hxx"
#include "base/version.hxx"

#include <boost/asio/streambuf.hpp>
#include <boost/asio/write.hpp>
#include <boost/beast/version.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

namespace http {
namespace out {

constexpr char whitespace = ' ';

namespace prefix {
namespace version {

template<class Stream, class Source, class... Args>
auto push(Source& source, Args const&... args)
-> decltype (boost::asio::write(source, std::declval<boost::asio::streambuf>()))
{
    boost::asio::streambuf buffer{};
    Stream stream{std::addressof(buffer)};
    base::display::print(stream, "BeastHttp/", BEAST_HTTP_VERSION_VALUE, whitespace,
                         '[', BOOST_BEAST_VERSION_STRING, ']', whitespace);
    base::display::print<whitespace>(stream, args...);
    return boost::asio::write(source, buffer);
}

template<class Stream, class Source, class... Args>
auto pushn(Source& source, Args const&... args)
-> decltype (boost::asio::write(source, std::declval<boost::asio::streambuf>()))
{
    boost::asio::streambuf buffer{};
    Stream stream{std::addressof(buffer)};
    base::display::print(stream, "BeastHttp/", BEAST_HTTP_VERSION_VALUE, whitespace,
                         '[', BOOST_BEAST_VERSION_STRING, ']', whitespace);
    base::display::printline<whitespace>(stream, args...);
    return boost::asio::write(source, buffer);
}

namespace time {

template<class Stream, class Source, class... Args>
auto push(Source& source, Args const&... args)
-> decltype (boost::asio::write(source, std::declval<boost::asio::streambuf>()))
{
    boost::asio::streambuf buffer{};
    Stream stream{std::addressof(buffer)};
    base::display::print(stream, "BeastHttp/", BEAST_HTTP_VERSION_VALUE, whitespace,
                         '[', BOOST_BEAST_VERSION_STRING, ']', whitespace,
                         '(', boost::posix_time::second_clock::local_time(), ')', whitespace);
    base::display::print<whitespace>(stream, args...);
    return boost::asio::write(source, buffer);
}

template<class Stream, class Source, class... Args>
auto pushn(Source& source, Args const&... args)
-> decltype (boost::asio::write(source, std::declval<boost::asio::streambuf>()))
{
    boost::asio::streambuf buffer{};
    Stream stream{std::addressof(buffer)};
    base::display::print(stream, "BeastHttp/", BEAST_HTTP_VERSION_VALUE, whitespace,
                         '[', BOOST_BEAST_VERSION_STRING, ']', whitespace,
                         '(', boost::posix_time::second_clock::local_time(), ')', whitespace);
    base::display::printline<whitespace>(stream, args...);
    return boost::asio::write(source, buffer);
}

} // namespace time
} // namespace version
} // namespace prefix

template<class Stream, class Destination, class... Args>
auto push(Destination& destination, Args const&... args)
-> decltype (boost::asio::write(destination, std::declval<boost::asio::streambuf>()))
{
    boost::asio::streambuf buffer{};
    Stream stream{std::addressof(buffer)};
    base::display::print<whitespace>(stream, args...);
    return boost::asio::write(destination, buffer);
}

template<class Stream, class Destination, class... Args>
auto pushn(Destination& destination, Args const&... args)
-> decltype (boost::asio::write(destination, std::declval<boost::asio::streambuf>()))
{
    boost::asio::streambuf buffer{};
    Stream stream{std::addressof(buffer)};
    base::display::printline<whitespace>(stream, args...);
    return boost::asio::write(destination, buffer);
}

} // namespace out
} // namespace http

#endif // not defined BEASTHTTP_OUT_HXX
