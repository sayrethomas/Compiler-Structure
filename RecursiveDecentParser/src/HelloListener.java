// Generated from src/Hello.g4 by ANTLR 4.7
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link HelloParser}.
 */
public interface HelloListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link HelloParser#r}.
	 * @param ctx the parse tree
	 */
	void enterR(HelloParser.RContext ctx);
	/**
	 * Exit a parse tree produced by {@link HelloParser#r}.
	 * @param ctx the parse tree
	 */
	void exitR(HelloParser.RContext ctx);
	/**
	 * Enter a parse tree produced by {@link HelloParser#num}.
	 * @param ctx the parse tree
	 */
	void enterNum(HelloParser.NumContext ctx);
	/**
	 * Exit a parse tree produced by {@link HelloParser#num}.
	 * @param ctx the parse tree
	 */
	void exitNum(HelloParser.NumContext ctx);
	/**
	 * Enter a parse tree produced by {@link HelloParser#nums}.
	 * @param ctx the parse tree
	 */
	void enterNums(HelloParser.NumsContext ctx);
	/**
	 * Exit a parse tree produced by {@link HelloParser#nums}.
	 * @param ctx the parse tree
	 */
	void exitNums(HelloParser.NumsContext ctx);
}