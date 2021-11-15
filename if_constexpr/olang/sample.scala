// https://stackoverflow.com/questions/43956467/type-level-programming-in-scala/43959128
package const

package object num
{
  sealed trait Num
  case object Zero extends Num
  case class Succ[N <: Num](num: N) extends Num

  sealed abstract class List[+H, N <: Num](val size: N) {
    def ::[T >: H](value: T): List[T, Succ[N]] = Cons(value, this)
  }

  case object Nil extends List[Nothing, Zero.type](Zero)

  case class Cons[+H, N <: Num](head: H, tail: List[H, N]) extends
    List[H, Succ[N]](Succ(tail.size))
  type ::[+H, N <: Num] = Cons[H, N]

  trait EvenNum[N <: Num]
  implicit val zeroIsEven = new EvenNum[Zero.type] {}
  implicit def evenNPlusTwo[N <: Num](implicit evenN: EvenNum[N]) =
    new EvenNum[Succ[Succ[N]]] {}
}