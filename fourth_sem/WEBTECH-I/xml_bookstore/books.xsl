<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" encoding="UTF-8" indent="yes"/>

<xsl:template match="/">
  <html>
    <head>
      <title>Books with Price > 50.00</title>
      <style>
        body {font-family: Arial, sans-serif; margin: 40px; background: #f5fffa;}
        h1 {color: #006400;}
        table {border-collapse: collapse; width: 800px; margin-top: 20px;}
        th, td {border: 2px solid #006400; padding: 15px; text-align: center;}
        th {background-color: #90ee90; color: #006400;}
        .nobooks {color: red; font-size: 22px; font-weight: bold;}
      </style>
    </head>
    <body>
      <h1>Books with Price Greater Than $50.00</h1>

      <xsl:if test="bookstore/book[price > 50]">
        <table>
          <tr>
            <th>Title</th>
            <th>Author</th>
            <th>Year</th>
            <th>Price</th>
            <th>Category</th>
          </tr>
          <xsl:for-each select="bookstore/book[price > 50]">
            <tr>
              <td><xsl:value-of select="title"/></td>
              <td><xsl:value-of select="author"/></td>
              <td><xsl:value-of select="year"/></td>
              <td>$<xsl:value-of select="price"/></td>
              <td><xsl:value-of select="@category"/></td>
            </tr>
          </xsl:for-each>
        </table>
      </xsl:if>

      <xsl:if test="not(bookstore/book[price > 50])">
        <p class="nobooks">No book found with price > 50.00</p>
      </xsl:if>

    </body>
  </html>
</xsl:template>

</xsl:stylesheet>