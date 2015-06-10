Public Class Tests
    Inherits FormAppBase

    Private Sub Tests_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        DevTestPlatform.DevTestPlatform.Start("GenAvrPcb V2")
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        MsgBox(Pin.Current(1))
    End Sub
End Class
